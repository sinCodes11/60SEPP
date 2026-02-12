# SEPP Port Scanner v1.0

An async TCP port scanner written in C++20 with Boost.Asio. Built for speed and practical pentesting use on Kali Linux.

## Features

- Async TCP connect scanning with configurable concurrency
- Banner grabbing with timeout (won't hang on silent services)
- Comma-separated ports, ranges, or mixed: `-p 22,80,100-200,443`
- Multiple output formats: table, JSON, CSV, greppable
- 80+ well-known service identifications
- Live progress bar during scans
- Sorted output by port number
- Verbose mode to see closed ports
- Proper DNS resolution error handling

## Build (Kali Linux)

```bash
# Install dependencies
sudo apt update && sudo apt install -y cmake g++ libboost-all-dev

# Build
mkdir build && cd build
cmake ..
make -j$(nproc)
```

## Usage

```bash
# Scan common ports on a target
./portscanner -t 192.168.1.1 -p 1-1024

# Scan specific ports
./portscanner -t 10.0.0.1 -p 22,80,443,3306,8080

# Full TCP scan with high concurrency
./portscanner -t 192.168.1.1 -p 1-65535 -c 500

# JSON output for scripting
./portscanner -t 10.0.0.1 -p 1-1024 -o json > results.json

# Grep for open ports only
./portscanner -t 10.0.0.1 -p 1-1024 -o grep | grep OPEN

# Verbose mode (show closed ports too)
./portscanner -t 10.0.0.1 -p 1-100 -v
```

## Options

| Flag | Description | Default |
|------|-------------|---------|
| `-t` | Target hostname or IP | 127.0.0.1 |
| `-p` | Port specification | 1-1024 |
| `-c` | Max concurrent connections | 100 |
| `-T` | Connect timeout (seconds) | 2 |
| `-B` | Banner grab timeout (seconds) | 3 |
| `-o` | Output format: table/json/csv/grep | table |
| `-v` | Verbose (show closed ports) | off |

## Legal

Only scan systems you own or have explicit written authorization to test.
