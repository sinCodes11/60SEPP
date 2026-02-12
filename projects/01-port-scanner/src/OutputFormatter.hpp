#ifndef OUTPUTFORMATTER_HPP
#define OUTPUTFORMATTER_HPP

#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>
#include <mutex>

// Represents a single scan result for one port.
// We collect these during scanning, then format them all at the end.
struct ScanResult {
    uint16_t port;
    std::string state;    // "OPEN", "CLOSED", "FILTERED"
    std::string service;
    std::string banner;
};

// Formats scan output in different modes: table, JSON, CSV, or greppable.
// Results are accumulated thread-safely, then printed sorted by port number.
class OutputFormatter {
public:
    enum class Format { TABLE, JSON, CSV, GREP };

    explicit OutputFormatter(Format fmt = Format::TABLE);

    // Thread-safe: add a result from any async handler
    void addResult(ScanResult result);

    // Print all collected results, sorted by port number
    void print(bool verbose) const;

    // Return counts
    int openCount() const;
    int closedCount() const;
    int filteredCount() const;

private:
    Format format;
    mutable std::mutex mtx;
    std::vector<ScanResult> results;

    void printTable(bool verbose) const;
    void printJSON(bool verbose) const;
    void printCSV() const;
    void printGrep() const;
};

#endif // OUTPUTFORMATTER_HPP
