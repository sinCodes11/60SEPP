#ifndef PORTSCANNER_HPP
#define PORTSCANNER_HPP

#include <boost/asio.hpp>
#include <string>
#include <vector>
#include <queue>
#include <memory>
#include <atomic>
#include <cstdint>
#include <functional>

#include "ServiceDB.hpp"
#include "OutputFormatter.hpp"

using boost::asio::ip::tcp;

// Configuration for a scan -- passed in from main() after CLI parsing.
// Keeping config separate from the scanner makes it testable and clean.
struct ScanConfig {
    std::string target;                // Hostname or IP
    std::vector<uint16_t> ports;       // Resolved list of ports to scan
    int concurrency       = 100;       // Max simultaneous async connections
    int connect_timeout   = 2;         // Seconds to wait for TCP handshake
    int banner_timeout    = 3;         // Seconds to wait for banner after connect
    bool verbose          = false;     // Show closed ports too
    OutputFormatter::Format output_format = OutputFormatter::Format::TABLE;
};

class PortScanner {
public:
    explicit PortScanner(ScanConfig config);

    // Run the scan. Blocks until all ports are scanned.
    void run();

private:
    ScanConfig config;

    boost::asio::io_context io;
    boost::asio::strand<boost::asio::io_context::executor_type> strand{io.get_executor()};
    tcp::endpoint target_endpoint;

    std::queue<uint16_t> work_queue;
    std::atomic<int> in_flight{0};
    std::atomic<int> completed{0};
    int total_ports = 0;

    OutputFormatter formatter;

    // Pull next port from queue and scan it
    void scheduleNext();

    // Scan a single port: connect -> optionally grab banner -> record result
    void scanPort(uint16_t port);

    // Attempt to read a banner from an open port
    void grabBanner(std::shared_ptr<tcp::socket> socket,
                    std::shared_ptr<boost::asio::steady_timer> timer,
                    uint16_t port,
                    const std::string& service);

    // Record a result and kick off next scan
    void recordResult(uint16_t port, const std::string& state,
                      const std::string& service, const std::string& banner);

    // Print progress to stderr (doesn't pollute stdout for piping)
    void reportProgress();
};

// Parse a port specification string into a sorted, deduplicated vector.
// Supports: "80", "1-1024", "22,80,443", "22,80,100-200,443"
std::vector<uint16_t> parsePorts(const std::string& spec);

#endif // PORTSCANNER_HPP
