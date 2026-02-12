#include "PortScanner.hpp"
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <chrono>

// ============================================================
// PORT SPEC PARSER
// ============================================================
// Handles all these formats:
//   "80"           -> [80]
//   "1-1024"       -> [1, 2, 3, ... 1024]
//   "22,80,443"    -> [22, 80, 443]
//   "22,80,100-200,443,8000-8100"  -> combined, sorted, deduped
//
// The original scanner only handled "start-end" or a single number.
// This version handles comma-separated lists mixed with ranges,
// which is what you actually need during a pentest.

std::vector<uint16_t> parsePorts(const std::string& spec) {
    std::set<uint16_t> port_set;  // set auto-deduplicates and sorts

    std::stringstream ss(spec);
    std::string token;

    while (std::getline(ss, token, ',')) {
        // Trim whitespace
        token.erase(0, token.find_first_not_of(" \t"));
        token.erase(token.find_last_not_of(" \t") + 1);

        if (token.empty()) continue;

        auto dash = token.find('-');
        if (dash != std::string::npos) {
            // Range: "start-end"
            int start = std::stoi(token.substr(0, dash));
            int end   = std::stoi(token.substr(dash + 1));

            if (start < 1) start = 1;
            if (end > 65535) end = 65535;
            if (start > end) std::swap(start, end);

            for (int p = start; p <= end; p++) {
                port_set.insert(static_cast<uint16_t>(p));
            }
        } else {
            // Single port
            int p = std::stoi(token);
            if (p >= 1 && p <= 65535) {
                port_set.insert(static_cast<uint16_t>(p));
            }
        }
    }

    return std::vector<uint16_t>(port_set.begin(), port_set.end());
}

// ============================================================
// PORTSCANNER CONSTRUCTOR
// ============================================================

PortScanner::PortScanner(ScanConfig config)
    : config(std::move(config)),
      formatter(this->config.output_format)
{
    // Resolve the target hostname/IP to an endpoint.
    // The original had no error handling here -- a bad hostname
    // would crash with an uncaught boost::system::system_error.
    tcp::resolver resolver(io);
    boost::system::error_code ec;
    auto results = resolver.resolve(this->config.target, "", ec);

    if (ec) {
        std::cerr << "Error: Could not resolve '"
                  << this->config.target << "': "
                  << ec.message() << "\n";
        std::exit(1);
    }

    target_endpoint = *results.begin();

    // Load port queue
    for (uint16_t port : this->config.ports) {
        work_queue.push(port);
    }
    total_ports = static_cast<int>(this->config.ports.size());
}

// ============================================================
// RUN: Entry point -- starts the async scan loop
// ============================================================

void PortScanner::run() {
    auto start_time = std::chrono::steady_clock::now();

    // Print scan header to stderr (keeps stdout clean for piping)
    std::cerr << "Starting scan of " << config.target
              << " (" << target_endpoint.address().to_string() << ")\n"
              << "Scanning " << total_ports << " ports with "
              << config.concurrency << " concurrent connections\n"
              << "Connect timeout: " << config.connect_timeout << "s, "
              << "Banner timeout: " << config.banner_timeout << "s\n"
              << std::string(50, '-') << "\n";

    // Seed the work pool: post up to `concurrency` initial scans.
    // Each scan, when it finishes, calls scheduleNext() to pull
    // the next port from the queue -- self-replenishing pool pattern.
    for (int i = 0; i < config.concurrency && !work_queue.empty(); i++) {
        boost::asio::post(strand, [this]() { scheduleNext(); });
    }

    // io.run() blocks here until all async operations complete
    io.run();

    auto end_time = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
        end_time - start_time);

    // Clear progress line
    std::cerr << "\r" << std::string(60, ' ') << "\r";
    std::cerr << std::string(50, '-') << "\n";

    // Print sorted results to stdout
    formatter.print(config.verbose);

    // Print summary to stderr
    std::cerr << "\n" << std::string(50, '-') << "\n"
              << "Scan complete: " << total_ports << " ports scanned in "
              << duration.count() / 1000.0 << "s\n"
              << "  Open:     " << formatter.openCount() << "\n"
              << "  Closed:   " << formatter.closedCount() << "\n"
              << "  Filtered: " << formatter.filteredCount() << "\n";
}

// ============================================================
// SCHEDULE NEXT: Pull a port from the queue and scan it
// ============================================================

void PortScanner::scheduleNext() {
    if (work_queue.empty()) return;

    uint16_t port = work_queue.front();
    work_queue.pop();
    in_flight++;

    scanPort(port);
}

// ============================================================
// SCAN PORT: The core async connect + timeout logic
// ============================================================
// For each port, we race two async operations:
//   1. async_connect to the target
//   2. a steady_timer that fires after connect_timeout
//
// Whichever fires first wins:
//   - Connect succeeds first -> port is OPEN, try banner grab
//   - Connect fails first   -> port is CLOSED
//   - Timer fires first     -> port is FILTERED (no response)
//
// A shared `complete` flag prevents the loser from also running.

void PortScanner::scanPort(uint16_t port) {
    auto socket   = std::make_shared<tcp::socket>(io);
    auto timer    = std::make_shared<boost::asio::steady_timer>(io);
    auto complete = std::make_shared<bool>(false);

    tcp::endpoint ep(target_endpoint.address(), port);

    // Start the timeout timer
    timer->expires_after(std::chrono::seconds(config.connect_timeout));
    timer->async_wait(boost::asio::bind_executor(strand,
        [this, complete, socket, port](boost::system::error_code ec) {
            if (ec || *complete) return;  // Timer was cancelled or connect won
            *complete = true;

            boost::system::error_code close_ec;
            socket->close(close_ec);

            std::string service = ServiceDB::lookup(port);
            recordResult(port, "FILTERED", service, "---");
        }));

    // Start the async connect
    socket->async_connect(ep, boost::asio::bind_executor(strand,
        [this, socket, timer, port, complete](boost::system::error_code ec) {
            if (*complete) return;  // Timer already won
            *complete = true;
            timer->cancel();

            std::string service = ServiceDB::lookup(port);

            if (!ec) {
                // Connection succeeded -> port is OPEN
                // Try to grab a banner before recording the result
                grabBanner(socket, timer, port, service);
            } else {
                // Connection refused -> port is CLOSED
                boost::system::error_code close_ec;
                socket->close(close_ec);
                recordResult(port, "CLOSED", service, "---");
            }
        }));
}

// ============================================================
// GRAB BANNER: Read whatever the service sends after connect
// ============================================================
// Many services (SSH, FTP, SMTP, etc.) send a banner immediately
// after a TCP connection is established. We try to read it.
//
// BUG FIX from original: The original scanner had NO timeout on
// the banner read. If a service accepted the connection but never
// sent data (e.g., HTTP waits for a request), the scan would hang
// forever on that port. We add a banner_timeout here.

void PortScanner::grabBanner(std::shared_ptr<tcp::socket> socket,
                              std::shared_ptr<boost::asio::steady_timer> timer,
                              uint16_t port,
                              const std::string& service) {
    auto buf      = std::make_shared<std::array<char, 256>>();
    auto complete = std::make_shared<bool>(false);

    // Banner timeout -- don't wait forever
    timer->expires_after(std::chrono::seconds(config.banner_timeout));
    timer->async_wait(boost::asio::bind_executor(strand,
        [this, complete, socket, port, service](boost::system::error_code ec) {
            if (ec || *complete) return;
            *complete = true;

            boost::system::error_code close_ec;
            socket->close(close_ec);

            // No banner received within timeout -- still OPEN, just no banner
            recordResult(port, "OPEN", service, "---");
        }));

    // Try to read
    socket->async_read_some(boost::asio::buffer(*buf),
        boost::asio::bind_executor(strand,
        [this, socket, timer, port, buf, complete, service](
            boost::system::error_code ec, std::size_t bytes_read) {
            if (*complete) return;
            *complete = true;
            timer->cancel();

            std::string banner = "---";
            if (!ec && bytes_read > 0) {
                banner.assign(buf->data(), bytes_read);
            }

            boost::system::error_code close_ec;
            socket->close(close_ec);

            recordResult(port, "OPEN", service, banner);
        }));
}

// ============================================================
// RECORD RESULT: Store result, update progress, schedule next
// ============================================================

void PortScanner::recordResult(uint16_t port, const std::string& state,
                                const std::string& service,
                                const std::string& banner) {
    formatter.addResult({port, state, service, banner});

    in_flight--;
    completed++;

    reportProgress();
    scheduleNext();
}

// ============================================================
// REPORT PROGRESS: Show scan progress on stderr
// ============================================================

void PortScanner::reportProgress() {
    int done = completed.load();
    if (total_ports == 0) return;

    // Only update every 1% or every 10 ports (whichever is more frequent)
    int update_interval = std::max(1, total_ports / 100);
    if (done % update_interval != 0 && done != total_ports) return;

    int pct = (done * 100) / total_ports;
    int bar_width = 30;
    int filled = (pct * bar_width) / 100;

    std::cerr << "\r[";
    for (int i = 0; i < bar_width; i++) {
        std::cerr << (i < filled ? "#" : ".");
    }
    std::cerr << "] " << pct << "% (" << done << "/" << total_ports
              << ") open:" << formatter.openCount()
              << " filtered:" << formatter.filteredCount()
              << "   " << std::flush;
}
