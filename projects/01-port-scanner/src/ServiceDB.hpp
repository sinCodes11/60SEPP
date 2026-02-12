#ifndef SERVICEDB_HPP
#define SERVICEDB_HPP

#include <cstdint>
#include <string>
#include <unordered_map>

// Maps port numbers to well-known service names.
// This is the "knowledge base" of the scanner -- it knows what
// typically runs on each port so you can quickly identify services.
class ServiceDB {
public:
    // Returns the service name for a port, or "unknown" if not mapped
    static std::string lookup(uint16_t port);

    // Returns the full map (used for verbose output)
    static const std::unordered_map<uint16_t, std::string>& all();

private:
    static const std::unordered_map<uint16_t, std::string> services;
};

#endif // SERVICEDB_HPP
