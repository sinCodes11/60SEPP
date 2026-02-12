#include "OutputFormatter.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

// ANSI color codes for terminal output
constexpr const char* GREEN = "\033[32m";
constexpr const char* RED   = "\033[31m";
constexpr const char* YELLOW = "\033[33m";
constexpr const char* RESET = "\033[0m";
constexpr const char* BOLD  = "\033[1m";

OutputFormatter::OutputFormatter(Format fmt) : format(fmt) {}

void OutputFormatter::addResult(ScanResult result) {
    std::lock_guard<std::mutex> lock(mtx);
    results.push_back(std::move(result));
}

void OutputFormatter::print(bool verbose) const {
    // Sort results by port number before printing
    std::lock_guard<std::mutex> lock(mtx);
    auto sorted = results;
    std::sort(sorted.begin(), sorted.end(),
        [](const ScanResult& a, const ScanResult& b) {
            return a.port < b.port;
        });

    // In non-verbose mode, only show OPEN and FILTERED ports
    std::vector<ScanResult> filtered;
    if (!verbose) {
        for (const auto& r : sorted) {
            if (r.state != "CLOSED") {
                filtered.push_back(r);
            }
        }
    } else {
        filtered = sorted;
    }

    // Temporarily swap in filtered results for printing
    auto& printable = filtered;

    switch (format) {
        case Format::TABLE: printTable(verbose); break;
        case Format::JSON:  printJSON(verbose);  break;
        case Format::CSV:   printCSV();          break;
        case Format::GREP:  printGrep();         break;
    }
}

int OutputFormatter::openCount() const {
    std::lock_guard<std::mutex> lock(mtx);
    int count = 0;
    for (const auto& r : results) {
        if (r.state == "OPEN") count++;
    }
    return count;
}

int OutputFormatter::closedCount() const {
    std::lock_guard<std::mutex> lock(mtx);
    int count = 0;
    for (const auto& r : results) {
        if (r.state == "CLOSED") count++;
    }
    return count;
}

int OutputFormatter::filteredCount() const {
    std::lock_guard<std::mutex> lock(mtx);
    int count = 0;
    for (const auto& r : results) {
        if (r.state == "FILTERED") count++;
    }
    return count;
}

void OutputFormatter::printTable(bool verbose) const {
    // Sort
    auto sorted = results;
    std::sort(sorted.begin(), sorted.end(),
        [](const ScanResult& a, const ScanResult& b) {
            return a.port < b.port;
        });

    // Header
    std::cout << BOLD
              << std::left << std::setw(10) << "PORT"
              << std::setw(12) << "STATE"
              << std::setw(22) << "SERVICE"
              << "BANNER"
              << RESET << "\n";

    std::cout << std::string(66, '-') << "\n";

    for (const auto& r : sorted) {
        if (!verbose && r.state == "CLOSED") continue;

        const char* color = RESET;
        if (r.state == "OPEN")     color = GREEN;
        if (r.state == "CLOSED")   color = RED;
        if (r.state == "FILTERED") color = YELLOW;

        std::cout << std::left << std::setw(10) << r.port
                  << color << std::setw(12) << r.state << RESET
                  << std::setw(22) << r.service;

        // Clean banner: strip newlines/control chars for table display
        std::string clean_banner;
        for (char c : r.banner) {
            if (c >= 32 && c < 127) clean_banner += c;
        }
        if (clean_banner.length() > 50) {
            clean_banner = clean_banner.substr(0, 47) + "...";
        }
        std::cout << clean_banner << "\n";
    }
}

void OutputFormatter::printJSON(bool verbose) const {
    auto sorted = results;
    std::sort(sorted.begin(), sorted.end(),
        [](const ScanResult& a, const ScanResult& b) {
            return a.port < b.port;
        });

    std::cout << "[\n";
    bool first = true;
    for (const auto& r : sorted) {
        if (!verbose && r.state == "CLOSED") continue;
        if (!first) std::cout << ",\n";
        first = false;

        // Escape special chars in banner for valid JSON
        std::string escaped;
        for (char c : r.banner) {
            if (c == '"')       escaped += "\\\"";
            else if (c == '\\') escaped += "\\\\";
            else if (c == '\n') escaped += "\\n";
            else if (c == '\r') escaped += "\\r";
            else if (c == '\t') escaped += "\\t";
            else if (c >= 32)   escaped += c;
        }

        std::cout << "  {"
                  << "\"port\":" << r.port << ","
                  << "\"state\":\"" << r.state << "\","
                  << "\"service\":\"" << r.service << "\","
                  << "\"banner\":\"" << escaped << "\""
                  << "}";
    }
    std::cout << "\n]\n";
}

void OutputFormatter::printCSV() const {
    auto sorted = results;
    std::sort(sorted.begin(), sorted.end(),
        [](const ScanResult& a, const ScanResult& b) {
            return a.port < b.port;
        });

    std::cout << "port,state,service,banner\n";
    for (const auto& r : sorted) {
        // CSV-escape banner (wrap in quotes, double any quotes)
        std::string escaped;
        for (char c : r.banner) {
            if (c == '"') escaped += "\"\"";
            else if (c >= 32) escaped += c;
        }
        std::cout << r.port << ","
                  << r.state << ","
                  << r.service << ","
                  << "\"" << escaped << "\"\n";
    }
}

void OutputFormatter::printGrep() const {
    auto sorted = results;
    std::sort(sorted.begin(), sorted.end(),
        [](const ScanResult& a, const ScanResult& b) {
            return a.port < b.port;
        });

    // Nmap-style greppable output: Host: x Ports: 22/open/tcp//ssh///
    for (const auto& r : sorted) {
        std::cout << r.port << "/" << r.state << "/tcp//"
                  << r.service << "///" << r.banner << "\n";
    }
}
