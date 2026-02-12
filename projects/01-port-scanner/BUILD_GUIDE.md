# Build Guide: TCP Port Scanner

**How this project was built, step by step.**
Read this to understand every decision, every file, and every concept.

---

## Table of Contents

1. [What Are We Building?](#1-what-are-we-building)
2. [Core Concepts You Need First](#2-core-concepts-you-need-first)
3. [Project Structure — Why These Files?](#3-project-structure--why-these-files)
4. [Step 1: The Service Database](#step-1-the-service-database)
5. [Step 2: The Output Formatter](#step-2-the-output-formatter)
6. [Step 3: Port Parsing](#step-3-port-parsing)
7. [Step 4: The Scanner Core — Async Connect](#step-4-the-scanner-core--async-connect)
8. [Step 5: Banner Grabbing](#step-5-banner-grabbing)
9. [Step 6: Concurrency Control](#step-6-concurrency-control)
10. [Step 7: The CLI (main.cpp)](#step-7-the-cli-maincpp)
11. [Step 8: Building with CMake](#step-8-building-with-cmake)
12. [Bugs We Fixed From the Original](#bugs-we-fixed-from-the-original)
13. [How to Extend This Project](#how-to-extend-this-project)

---

## 1. What Are We Building?

A **TCP connect scanner**. It tries to complete a full TCP 3-way handshake with every port you specify on a target machine. Based on what happens, it classifies each port:

| Response | Classification | What it means |
|----------|---------------|---------------|
| TCP handshake completes | **OPEN** | A service is listening |
| RST packet received | **CLOSED** | Nothing is listening |
| No response within timeout | **FILTERED** | Firewall is dropping packets |

After connecting to an open port, we also try to **grab the banner** — many services (SSH, FTP, SMTP) announce themselves immediately after a connection.

### Why C++ with Boost.Asio?

- **Speed**: We can have hundreds of connections in-flight simultaneously using async I/O, without creating hundreds of OS threads
- **Control**: Direct access to socket behavior and timeouts
- **Real-world relevance**: Understanding async networking is critical for security tooling

### What makes this different from the original?

The original was functional but had bugs and missing features. Our version:
- Fixes a parsing bug with `uint8_t` timeouts
- Adds a timeout to banner grabbing (original would hang forever)
- Supports comma-separated port lists
- Has 4 output formats (table, JSON, CSV, greppable)
- Shows a live progress bar
- Sorts output by port number
- Actually implements the verbose flag
- Handles DNS resolution failures gracefully
- Closes sockets properly on all code paths

---

## 2. Core Concepts You Need First

### TCP 3-Way Handshake

```
Client              Server
  |--- SYN ----------->|    "Hey, want to connect?"
  |<-- SYN-ACK --------|    "Sure, I'm listening"
  |--- ACK ----------->|    "Great, we're connected"
```

Our scanner initiates this handshake. If it completes, the port is open. If the server sends RST instead of SYN-ACK, the port is closed.

### Async I/O (non-blocking sockets)

Normal (blocking) approach:
```
connect to port 22    -> wait 2 seconds -> got answer
connect to port 23    -> wait 2 seconds -> got answer
connect to port 24    -> wait 2 seconds -> got answer
Total: 6 seconds for 3 ports
```

Async approach:
```
start connect to port 22  |
start connect to port 23  |  all start at once
start connect to port 24  |
... wait for any to finish ...
Total: ~2 seconds for 3 ports
```

Boost.Asio manages this for us. We call `async_connect`, and Asio calls our callback function when the connection succeeds or fails. Meanwhile, Asio can manage thousands of other connections.

### What is a Strand?

When you have multiple async operations completing, their callbacks can fire in any order. A **strand** is a serialization mechanism — it guarantees that no two callbacks run simultaneously, even if you have multiple threads. This prevents race conditions when we update shared state (the work queue, result counter, etc.).

---

## 3. Project Structure — Why These Files?

```
01-port-scanner/
├── CMakeLists.txt          # Build configuration
├── main.cpp                # CLI entry point — parses args, calls scanner
├── README.md               # How to use it
├── BUILD_GUIDE.md          # You're reading this
└── src/
    ├── PortScanner.hpp     # Scanner class declaration
    ├── PortScanner.cpp     # Scanner implementation (the core)
    ├── ServiceDB.hpp       # Port-to-service-name mapping
    ├── ServiceDB.cpp       # The actual database of 80+ services
    ├── OutputFormatter.hpp # Result storage + output formatting
    └── OutputFormatter.cpp # Table, JSON, CSV, grep formatters
```

**Why separate files?**

Each file has one job (Single Responsibility):
- `ServiceDB` knows what services run on what ports — nothing else
- `OutputFormatter` knows how to store and display results — nothing else
- `PortScanner` knows how to scan — nothing else
- `main.cpp` just wires CLI arguments to the scanner

This means you can change the output format without touching scanner logic. You can add 100 more services without touching anything else. Each piece is independently understandable.

---

## Step 1: The Service Database

**File: `src/ServiceDB.hpp` + `src/ServiceDB.cpp`**

**What it does**: Maps port numbers to human-readable service names.

**Why we built it first**: It's the simplest component with zero dependencies. Starting with the easiest piece lets you get something compiling early.

**Key decisions:**

1. **Static map vs. reading /etc/services**: We use a compiled-in map because:
   - No filesystem dependency (works everywhere)
   - No startup I/O cost
   - Predictable behavior
   - 80+ entries covers the vast majority of real scans

2. **`unordered_map` vs. `map`**: We use `unordered_map` because we only need lookup-by-key (O(1)) and never need sorted iteration of the service list.

3. **Static class methods, not an instance**: There's no state to manage — the service list never changes at runtime. Static methods communicate this clearly.

**How to read the code:**

```cpp
// This is the lookup function. That's it.
std::string ServiceDB::lookup(uint16_t port) {
    auto it = services.find(port);       // O(1) hash lookup
    if (it != services.end()) {
        return it->second;               // Found — return service name
    }
    return "unknown";                    // Not in our database
}
```

---

## Step 2: The Output Formatter

**File: `src/OutputFormatter.hpp` + `src/OutputFormatter.cpp`**

**What it does**: Collects scan results and prints them in your chosen format.

**Why we built it second**: It depends on nothing except the `ScanResult` struct. Building it before the scanner means we have a place to put results before we write the code that generates them.

**Key decisions:**

1. **Collect-then-print vs. print-as-you-go**: The original printed results as each port completed, which meant output was in random order. We collect all results in a vector, sort by port number, then print once at the end. Much more readable.

2. **Thread-safe with mutex**: Multiple async handlers call `addResult()` concurrently. The mutex ensures the results vector doesn't get corrupted.

3. **Four output formats**:
   - **Table**: Human-readable with colors — for interactive use
   - **JSON**: Machine-readable — pipe into `jq`, store in databases
   - **CSV**: Spreadsheet-friendly — import into Excel/Google Sheets
   - **Grep**: Nmap-style — easy to filter with `grep`, `awk`, `cut`

**How the result struct works:**

```cpp
struct ScanResult {
    uint16_t port;        // 22, 80, 443, etc.
    std::string state;    // "OPEN", "CLOSED", "FILTERED"
    std::string service;  // "SSH", "HTTP", "unknown"
    std::string banner;   // "SSH-2.0-OpenSSH_9.2" or "---"
};
```

Every port scan produces exactly one of these. Simple, flat, no inheritance.

---

## Step 3: Port Parsing

**Function: `parsePorts()` in `src/PortScanner.cpp`**

**What it does**: Turns a string like `"22,80,100-200,443"` into a sorted, deduplicated vector of port numbers.

**Why it matters**: The original could only handle `"start-end"` or a single number. In real pentesting, you often want to scan specific ports AND ranges together.

**Algorithm:**

```
Input: "22,80,100-200,443"

1. Split by comma: ["22", "80", "100-200", "443"]

2. For each token:
   - Has a dash? It's a range -> expand to individual ports
   - No dash? It's a single port -> add it

3. We use a std::set, which automatically:
   - Deduplicates (if you write "80,80" you get one 80)
   - Sorts (output is always in port order)

4. Convert set to vector and return

Output: [22, 80, 100, 101, 102, ..., 200, 443]
```

**Why `std::set` instead of `std::vector` + sort + unique?**
Less code, same result. The set handles dedup and sorting as you insert. For port numbers (max 65535 entries), performance is identical.

---

## Step 4: The Scanner Core — Async Connect

**File: `src/PortScanner.cpp`, function `scanPort()`**

This is the heart of the scanner. For each port, we:

```
1. Create a socket and a timer
2. Start both racing:
   - Timer: fires after connect_timeout seconds
   - Connect: tries TCP handshake to target:port
3. Whoever finishes first sets `complete = true`
   The loser sees complete==true and does nothing
```

**The race pattern in detail:**

```cpp
auto complete = std::make_shared<bool>(false);

// ARM THE TIMER
timer->expires_after(seconds(config.connect_timeout));
timer->async_wait([&](error_code ec) {
    if (ec || *complete) return;   // Connect already won
    *complete = true;              // I won — port is FILTERED
    socket->close();               // Kill the connection attempt
    recordResult(port, "FILTERED", ...);
});

// START THE CONNECT
socket->async_connect(endpoint, [&](error_code ec) {
    if (*complete) return;         // Timer already won
    *complete = true;              // I won
    timer->cancel();               // Kill the timer

    if (!ec) {
        // Handshake completed -> OPEN
        grabBanner(socket, ...);
    } else {
        // RST received -> CLOSED
        recordResult(port, "CLOSED", ...);
    }
});
```

**Why `shared_ptr<bool>` for `complete`?**
Both callbacks need to read/write the same flag. `shared_ptr` keeps it alive until both callbacks have finished (or been cancelled). Since both run on the same strand, there's no data race.

---

## Step 5: Banner Grabbing

**Function: `grabBanner()` in `src/PortScanner.cpp`**

After a successful connect, many services send a "banner" — identifying text:
- SSH: `SSH-2.0-OpenSSH_9.2p1 Debian-2`
- FTP: `220 ProFTPD Server`
- SMTP: `220 mail.example.com ESMTP Postfix`

We use the same timer-race pattern as the connect phase:

```
1. Start a read with a timer
2. If data arrives -> capture it as the banner
3. If timer fires first -> record "---" (no banner, but port is still OPEN)
```

**Critical bug fix**: The original scanner had NO timeout on the banner read. Services like HTTP don't send anything until they receive a request. Without a timeout, the scanner would wait *forever* on every HTTP port. Our `banner_timeout` (default 3 seconds) prevents this.

---

## Step 6: Concurrency Control

**The self-replenishing pool pattern:**

```
Initial state: queue has 1000 ports, concurrency = 100

1. start() posts 100 calls to scheduleNext()
2. Each scheduleNext() pulls ONE port and scans it
3. When a scan finishes, recordResult() calls scheduleNext() again
4. This pulls the next port from the queue
5. So there are always ~100 scans in-flight until the queue empties
```

**Visualized:**

```
Time -->

Slot 1: [port 1    ] [port 101  ] [port 201  ] ...
Slot 2: [port 2    ] [port 102  ] [port 202  ] ...
Slot 3: [port 3    ] [port 103  ] [port 203  ] ...
...
Slot 100: [port 100] [port 200  ] [port 300  ] ...
```

Each slot finishes its port and immediately picks up the next one. No slot is ever idle while there's work in the queue.

**Why not just launch all 65535 at once?**
Operating systems have limits on open file descriptors (sockets). Launching 65535 simultaneous connections would hit that limit and crash. The concurrency cap keeps us within safe limits.

---

## Step 7: The CLI (main.cpp)

**What it does**: Parses command-line arguments using Boost.Program_Options and constructs a `ScanConfig` struct.

**Design decisions:**

1. **Config struct, not direct globals**: The scanner takes a `ScanConfig` object. This means:
   - main.cpp is responsible for CLI parsing
   - PortScanner is responsible for scanning
   - Neither knows about the other's internals

2. **Fixed the uint8_t bug**: The original used `uint8_t` for the timeout CLI parameter. Boost.Program_Options treats `uint8_t` as a character, not a number. Passing `--timeout 2` would read ASCII '2' (decimal 50), not the number 2. We use `int` at the CLI layer.

3. **Sensible defaults**:
   - Target: localhost (safe default)
   - Ports: 1-1024 (well-known ports)
   - Concurrency: 100 (safe for most systems)
   - Timeouts: 2s connect, 3s banner

4. **Stderr for status, stdout for data**: All progress bars, scan info, and summaries go to stderr. Only scan results go to stdout. This means you can pipe results:
   ```bash
   ./portscanner -t 10.0.0.1 -o json > results.json
   # You see progress in terminal, results go to file
   ```

---

## Step 8: Building with CMake

**File: `CMakeLists.txt`**

```cmake
cmake_minimum_required(VERSION 3.20)   # Need 3.20+ for C++20 support
project(portscanner VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)             # We use C++20 features
set(CMAKE_CXX_STANDARD_REQUIRED ON)    # Fail if compiler can't do C++20

find_package(Boost REQUIRED COMPONENTS program_options)  # Find Boost on system

add_executable(portscanner              # Our binary
    main.cpp                            # Entry point
    src/PortScanner.cpp                 # Scanner logic
    src/ServiceDB.cpp                   # Service database
    src/OutputFormatter.cpp             # Output formatting
)

target_include_directories(portscanner PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(portscanner Boost::program_options)
```

**Build commands on Kali:**

```bash
sudo apt update && sudo apt install -y cmake g++ libboost-all-dev
mkdir build && cd build
cmake ..
make -j$(nproc)
```

**What each command does:**
- `cmake ..` reads CMakeLists.txt, finds Boost, generates Makefiles
- `make -j$(nproc)` compiles all .cpp files using all CPU cores
- Output: `./portscanner` binary in the build directory

---

## Bugs We Fixed From the Original

### Bug 1: uint8_t CLI Parsing
**Original**: `po::value<uint8_t>()->default_value(2)` for timeout
**Problem**: Boost reads it as a character. `--timeout 2` stores ASCII 50, not 2.
**Fix**: Use `int` at the CLI layer, let the config struct hold the value.

### Bug 2: Banner Read Hangs Forever
**Original**: No timeout on `async_read_some` after connect.
**Problem**: HTTP/HTTPS ports accept connections but don't send data unprompted. Scanner hangs.
**Fix**: Added `banner_timeout` with a timer race, same pattern as the connect phase.

### Bug 3: Sockets Not Closed
**Original**: Only the FILTERED path closed the socket.
**Problem**: OPEN and CLOSED paths relied on shared_ptr destructor. Not reliable with async ops still pending.
**Fix**: Explicit `socket->close()` on all three code paths.

### Bug 4: No DNS Error Handling
**Original**: `resolver.resolve()` throws on bad hostnames. Unhandled.
**Problem**: Crash with a confusing Boost exception trace.
**Fix**: Catch the error with `error_code` overload, print a clean message, exit.

### Bug 5: Verbose Flag Declared But Unused
**Original**: `("verbose,v", "verbose output")` existed but was never checked.
**Fix**: Non-verbose mode hides CLOSED ports (which is what you want 99% of the time). Verbose shows everything.

### Bug 6: Random Output Order
**Original**: Results printed as each port completed (random order).
**Fix**: Collect all results, sort by port number, print at the end.

---

## How to Extend This Project

Ideas for adding more capability:

1. **SYN scanning (stealth)**: Use raw sockets to send SYN packets without completing the handshake. Requires root. Harder to detect.

2. **UDP scanning**: Send UDP probes. Trickier because UDP is connectionless — you have to send data and interpret ICMP responses.

3. **OS fingerprinting**: Analyze TCP/IP stack behavior (TTL values, window sizes, options) to guess the target's operating system.

4. **Service version detection**: After grabbing a banner, parse it to extract version numbers. Useful for vulnerability matching.

5. **Output to file**: Add a `-f` flag to write results directly to a file.

6. **Load ports from /etc/services**: Add an option to load the service database from the system file instead of the compiled-in map.

7. **Rate limiting**: Add a `--rate` flag to limit packets per second, useful when you need to be gentle on fragile networks.

8. **IPv6 support**: The resolver already handles IPv6, but you'd want to add a `-6` flag and test it.
