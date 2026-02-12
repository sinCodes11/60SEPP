#include "src/PortScanner.hpp"
#include <boost/program_options.hpp>
#include <iostream>
#include <string>

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
    po::options_description desc("SEPP Port Scanner v1.0 - Options");
    desc.add_options()
        ("help,h",    "Show this help message")
        ("target,t",  po::value<std::string>()->default_value("127.0.0.1"),
                       "Target hostname or IP address")
        ("ports,p",   po::value<std::string>()->default_value("1-1024"),
                       "Port spec: 80 | 1-1024 | 22,80,443 | 22,80,100-200")
        ("concurrent,c", po::value<int>()->default_value(100),
                       "Max concurrent connections")
        ("timeout,T",    po::value<int>()->default_value(2),
                       "Connect timeout in seconds")
        ("banner-timeout,B", po::value<int>()->default_value(3),
                       "Banner grab timeout in seconds")
        ("output,o",  po::value<std::string>()->default_value("table"),
                       "Output format: table | json | csv | grep")
        ("verbose,v", "Show all ports including closed");

    po::variables_map vm;

    try {
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);
    } catch (const po::error& e) {
        std::cerr << "Error: " << e.what() << "\n\n" << desc << "\n";
        return 1;
    }

    if (vm.count("help")) {
        std::cout << desc << "\n"
                  << "Examples:\n"
                  << "  Scan common ports on localhost:\n"
                  << "    ./portscanner -t 127.0.0.1 -p 1-1024\n\n"
                  << "  Full TCP scan:\n"
                  << "    ./portscanner -t 192.168.1.1 -p 1-65535 -c 500\n\n"
                  << "  Scan specific ports:\n"
                  << "    ./portscanner -t 10.0.0.1 -p 22,80,443,3306,8080\n\n"
                  << "  Mixed ranges and specific ports:\n"
                  << "    ./portscanner -t target.com -p 22,80,100-200,443\n\n"
                  << "  JSON output for scripting:\n"
                  << "    ./portscanner -t 10.0.0.1 -p 1-1024 -o json\n\n"
                  << "  Verbose scan with all ports shown:\n"
                  << "    ./portscanner -t 10.0.0.1 -p 1-100 -v\n\n"
                  << "  Pipe greppable output:\n"
                  << "    ./portscanner -t 10.0.0.1 -p 1-1024 -o grep | grep OPEN\n\n"
                  << "DISCLAIMER: Only scan systems you own or have\n"
                  << "explicit written authorization to test.\n";
        return 0;
    }

    // Build config from CLI args
    ScanConfig config;
    config.target          = vm["target"].as<std::string>();
    config.connect_timeout = vm["timeout"].as<int>();
    config.banner_timeout  = vm["banner-timeout"].as<int>();
    config.concurrency     = vm["concurrent"].as<int>();
    config.verbose         = vm.count("verbose") > 0;

    // Parse output format
    std::string fmt = vm["output"].as<std::string>();
    if (fmt == "json")      config.output_format = OutputFormatter::Format::JSON;
    else if (fmt == "csv")  config.output_format = OutputFormatter::Format::CSV;
    else if (fmt == "grep") config.output_format = OutputFormatter::Format::GREP;
    else                    config.output_format = OutputFormatter::Format::TABLE;

    // Parse port specification
    try {
        config.ports = parsePorts(vm["ports"].as<std::string>());
    } catch (const std::exception& e) {
        std::cerr << "Error: Invalid port specification '"
                  << vm["ports"].as<std::string>() << "'\n"
                  << "Use formats like: 80, 1-1024, 22,80,443\n";
        return 1;
    }

    if (config.ports.empty()) {
        std::cerr << "Error: No valid ports specified.\n";
        return 1;
    }

    // Sanity check concurrency
    if (config.concurrency < 1) config.concurrency = 1;
    if (config.concurrency > 10000) config.concurrency = 10000;

    // Run the scan
    PortScanner scanner(std::move(config));
    scanner.run();

    return 0;
}
