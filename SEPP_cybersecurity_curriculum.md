# Cybersecurity Engineering Curriculum

## Purpose and Scope

Extends the SEPP Systems Engineering Curriculum (SEPP_sys_curriculum.md) with 60 cybersecurity projects sourced from [CarterPerez-dev/Cybersecurity-Projects](https://github.com/CarterPerez-dev/Cybersecurity-Projects). Organizes all projects from beginner to advanced, maps cross-dependencies between systems engineering and cybersecurity tracks, and establishes the foundation for building an all-in-one AI Cybersecurity iOS application as the capstone.

## Execution Context

- Two parallel tracks: **Systems Engineering** (60 projects) + **Cybersecurity** (60 projects) = **120 total projects**
- Tracks share dependencies: systems knowledge enables deeper cybersecurity work and vice versa
- Timeline: 5-6 years total (tracks can be interleaved, not strictly sequential)
- Capstone: All-in-one AI Cybersecurity iOS App integrating learned skills from both tracks
- Source repo: https://github.com/CarterPerez-dev/Cybersecurity-Projects (14 implemented, 46 synopses)

---

# Combined Curriculum Overview

## Track A: Systems Engineering (from SEPP_sys_curriculum.md)

| Tier | Name | Projects | Timeline |
|------|------|----------|----------|
| 1 | Foundational Tools | 8 | Weeks 1-8 |
| 2 | Low-Level Systems | 7 | Months 3-6 |
| 3 | Compilation & Language Systems | 6 | Months 7-10 |
| 4 | Networking & Distributed Systems | 9 | Months 11-14 |
| 5 | Data Systems | 4 | Months 15-17 |
| 6 | Containerization & Virtualization | 5 | Months 18-21 |
| 7 | Operating Systems | 6 | Months 22-26 |
| 8 | Graphics & Multimedia | 5 | Months 27-30 |
| 9 | UI & Browser Systems | 5 | Months 31-35 |
| 10 | Advanced Distributed Systems | 4 | Months 36-40 |
| 11 | Machine Learning | 1 | Months 41-44 |

## Track B: Cybersecurity Engineering (NEW -- this document)

| Phase | Name | Projects | Timeline |
|-------|------|----------|----------|
| B1 | Security Fundamentals | 10 | Months 1-3 |
| B2 | Network Security & Reconnaissance | 10 | Months 4-7 |
| B3 | Offensive Security Basics | 10 | Months 8-12 |
| B4 | Defensive Security & Monitoring | 10 | Months 13-18 |
| B5 | Application & API Security | 8 | Months 19-24 |
| B6 | Cloud, Container & Infrastructure Security | 6 | Months 25-30 |
| B7 | Advanced Offensive Security | 6 | Months 31-36 |
| B8 | AI/ML Security & Advanced Defense | 6 | Months 37-44 |
| B9 | Capstone: AI Cybersecurity iOS Platform | 4 | Months 45-52 |

---

# Track B: Cybersecurity Engineering -- Full Project Breakdown

---

## Phase B1: Security Fundamentals (Beginner)
**Core concepts:** Encoding, cryptography basics, data privacy, CLI tool development
**Estimated time:** 2-3 months
**Systems track synergy:** Pairs with Tier 1 (foundational tools, I/O, parsing)

### Project B1 (CS-01): Base64 Encoder/Decoder
- **Source:** Repo -- PROJECTS/beginner/base64-tool/ (IMPLEMENTED)
- **Language:** Python
- **Time:** 2-4 hours
- **What you build:** Multi-format encoding/decoding CLI (Base64, Base32, URL encoding) with auto-detection
- **What you learn:** Binary encoding schemes, CLI design patterns, auto-detection algorithms
- **Key skills:** Python packaging (pyproject.toml), testing, CLI argument parsing
- **Prerequisites:** Basic Python

### Project B2 (CS-02): Caesar Cipher
- **Source:** Repo -- PROJECTS/beginner/caesar-cipher/ (IMPLEMENTED)
- **Language:** Python
- **Time:** 4-5 hours
- **What you build:** Classical cipher implementation with brute-force frequency analysis
- **What you learn:** Classical cryptography, frequency analysis, brute force attacks
- **Key skills:** Modular code design, test-driven development
- **Prerequisites:** CS-01

### Project B3 (CS-03): Hash Cracker
- **Source:** Repo -- SYNOPSES/beginner/ (blueprint)
- **Language:** C++
- **Time:** 5-6 hours
- **What you build:** Dictionary and brute-force hash cracking tool supporting MD5/SHA
- **What you learn:** Hash functions, dictionary attacks, rainbow tables concepts, computational complexity
- **Key skills:** C++ development, file I/O, hash library usage
- **Prerequisites:** CS-02
- **Systems synergy:** Benefits from Tier 1 memory allocator understanding

### Project B4 (CS-04): Steganography Tool
- **Source:** Repo -- SYNOPSES/beginner/ (blueprint)
- **Language:** Python
- **Time:** 5-6 hours
- **What you build:** Hide and extract secret messages in images using LSB (Least Significant Bit) technique
- **What you learn:** Image binary formats, bit manipulation, information hiding
- **Key skills:** Binary file I/O, image processing basics, PIL/Pillow
- **Prerequisites:** CS-01

### Project B5 (CS-05): Metadata Scrubber Tool
- **Source:** Repo -- PROJECTS/beginner/metadata-scrubber-tool/ (IMPLEMENTED)
- **Language:** Python
- **Time:** 10-12 hours
- **What you build:** Privacy tool that strips EXIF/metadata from JPEG, PNG, PDF, Word, Excel, PowerPoint files
- **What you learn:** File format internals (binary parsing), EXIF structures, privacy/OPSEC
- **Key skills:** Low-level binary parsing, batch processing, report generation, multi-format handling
- **Prerequisites:** CS-04
- **Note:** Substantial project despite beginner label -- involves 6+ file format parsers

### Project B6 (CS-06): Phishing URL Detector
- **Source:** Repo -- SYNOPSES/beginner/ (blueprint)
- **Language:** Python
- **Time:** 3-4 hours
- **What you build:** URL analysis tool detecting phishing indicators, typosquatting, suspicious patterns
- **What you learn:** URL structure, common phishing techniques, Levenshtein distance, heuristic analysis
- **Key skills:** String analysis, regular expressions, heuristic scoring
- **Prerequisites:** CS-01

### Project B7 (CS-07): Firewall Log Parser
- **Source:** Repo -- SYNOPSES/beginner/ (blueprint)
- **Language:** Bash + Python
- **Time:** 3-4 hours
- **What you build:** Parse and visualize firewall logs, detect patterns, generate reports
- **What you learn:** Log formats (syslog, iptables, pf), pattern recognition, data visualization
- **Key skills:** Text parsing, regex, data aggregation, basic visualization
- **Prerequisites:** CS-06

### Project B8 (CS-08): File Integrity Monitor
- **Source:** Repo -- SYNOPSES/beginner/ (blueprint)
- **Language:** Go
- **Time:** 7-8 hours
- **What you build:** Monitors directories for file changes using cryptographic checksums (SHA-256)
- **What you learn:** Cryptographic hashing for integrity, file system monitoring, change detection
- **Key skills:** Go development, goroutines, filesystem watchers, hash comparison
- **Prerequisites:** CS-03 (hashing concepts)
- **Systems synergy:** Benefits from Tier 2 file system understanding

### Project B9 (CS-09): Security News Scraper
- **Source:** Repo -- SYNOPSES/beginner/ (blueprint)
- **Language:** Python
- **Time:** 10-14 hours
- **What you build:** Aggregate cybersecurity news from multiple sources with CVE parsing and threat categorization
- **What you learn:** Web scraping, RSS feeds, CVE format, threat intelligence basics
- **Key skills:** HTTP requests, HTML parsing, data normalization, scheduling
- **Prerequisites:** CS-06, CS-07

### Project B10 (CS-10): Ransomware Simulator
- **Source:** Repo -- SYNOPSES/beginner/ (blueprint)
- **Language:** Python
- **Time:** 8-10 hours
- **What you build:** Educational ransomware simulation with AES encryption/decryption demo (sandboxed, no real harm)
- **What you learn:** Symmetric encryption (AES), file encryption workflows, ransomware mechanics for defense
- **Key skills:** Cryptography libraries, safe sandbox design, ethical considerations
- **Prerequisites:** CS-02, CS-03
- **CRITICAL:** Educational only -- sandboxed environment, ethical guidelines enforced

---

## Phase B2: Network Security & Reconnaissance (Beginner-Intermediate)
**Core concepts:** Network protocols, packet analysis, scanning, DNS, wireless security
**Estimated time:** 3-4 months
**Systems track synergy:** Pairs with Tier 2 (low-level systems) and Tier 4 (networking)

### Project B11 (CS-11): Simple Port Scanner
- **Source:** Repo -- PROJECTS/beginner/simple-port-scanner/ (IMPLEMENTED)
- **Language:** C++
- **Time:** 4-5 hours
- **What you build:** Async TCP port scanner with service detection and banner grabbing
- **What you learn:** TCP socket programming, async I/O, service fingerprinting, SYN scanning concepts
- **Key skills:** C++ networking, CMake builds, POSIX sockets, multithreading
- **Prerequisites:** Phase B1 complete

### Project B12 (CS-12): DNS Lookup CLI Tool
- **Source:** Repo -- PROJECTS/beginner/dns-lookup/ (IMPLEMENTED)
- **Language:** Python
- **Time:** 6-7 hours
- **What you build:** DNS record query tool (A, AAAA, MX, NS, TXT, SOA) with WHOIS integration and reverse DNS
- **What you learn:** DNS protocol, record types, WHOIS queries, domain infrastructure
- **Key skills:** dnspython library, network protocol handling, CLI design
- **Prerequisites:** CS-11

### Project B13 (CS-13): Network Traffic Analyzer
- **Source:** Repo -- PROJECTS/beginner/network-traffic-analyzer/ (IMPLEMENTED)
- **Language:** Python
- **Time:** 10-12 hours
- **What you build:** Packet capture and analysis tool with protocol dissection (TCP/UDP/ICMP/DNS/HTTP/TLS)
- **What you learn:** Packet structure, protocol layers, traffic patterns, deep packet inspection basics
- **Key skills:** Scapy/pcap, protocol parsers, rich terminal display, traffic visualization
- **Prerequisites:** CS-11, CS-12
- **Systems synergy:** Directly benefits from Tier 4 networking stack understanding

### Project B14 (CS-14): MAC Address Spoofer
- **Source:** Repo -- SYNOPSES/beginner/ (blueprint)
- **Language:** Python
- **Time:** 3-4 hours
- **What you build:** Change network interface MAC addresses with vendor lookup database
- **What you learn:** MAC addresses, network interfaces, vendor OUI database, identity masking
- **Key skills:** Subprocess management, network interface control, OUI parsing
- **Prerequisites:** CS-11

### Project B15 (CS-15): WiFi Network Scanner
- **Source:** Repo -- SYNOPSES/beginner/ (blueprint)
- **Language:** Python
- **Time:** 9-10 hours
- **What you build:** Wireless network discovery with encryption detection, signal analysis, rogue AP detection
- **What you learn:** 802.11 protocols, WEP/WPA/WPA2/WPA3, channel analysis, wireless security
- **Key skills:** Scapy wireless, monitor mode, channel hopping, signal processing
- **Prerequisites:** CS-13, CS-14

### Project B16 (CS-16): ARP Spoofing Detector
- **Source:** Repo -- SYNOPSES/beginner/ (blueprint)
- **Language:** Python
- **Time:** 5-6 hours
- **What you build:** Detect ARP spoofing/MITM attacks by tracking MAC-IP binding changes over time
- **What you learn:** ARP protocol, MITM attack mechanics, network anomaly detection
- **Key skills:** ARP table parsing, packet sniffing, alerting, IP-MAC correlation
- **Prerequisites:** CS-13, CS-14

### Project B17 (CS-17): SSH Brute Force Detector
- **Source:** Repo -- SYNOPSES/beginner/ (blueprint)
- **Language:** Python
- **Time:** 2-4 hours
- **What you build:** Monitor auth logs for SSH brute force patterns and auto-block offending IPs
- **What you learn:** Log analysis, pattern matching, automated response, fail2ban concepts
- **Key skills:** Log parsing, IP blocking (iptables/ufw), rate tracking, alerting
- **Prerequisites:** CS-07 (log parsing)

### Project B18 (CS-18): Simple Vulnerability Scanner
- **Source:** Repo -- PROJECTS/beginner/simple-vulnerability-scanner/ (IMPLEMENTED)
- **Language:** Go
- **Time:** 12-14 hours
- **What you build:** Software vulnerability checker against CVE/OSV databases with SBOM generation ("angela")
- **What you learn:** CVE databases, OSV API, dependency scanning, SBOM (Software Bill of Materials)
- **Key skills:** Go modules, API integration, SBOM standards, vulnerability scoring
- **Prerequisites:** CS-11
- **Note:** Multi-package Go project -- more complex than other beginner projects

### Project B19 (CS-19): SSL/TLS Certificate Scanner
- **Source:** Repo -- SYNOPSES/intermediate/ (blueprint)
- **Language:** Go
- **Time:** 2-4 days
- **What you build:** Scan domains for SSL/TLS misconfigurations, weak ciphers, expired certificates
- **What you learn:** TLS handshake, certificate chains, cipher suites, PKI infrastructure
- **Key skills:** Go crypto/tls, X.509 parsing, certificate validation, OCSP checking
- **Prerequisites:** CS-18, CS-12
- **Systems synergy:** Benefits from Tier 2 encryption algorithm understanding

### Project B20 (CS-20): Windows Registry Monitor
- **Source:** Repo -- SYNOPSES/beginner/ (blueprint)
- **Language:** Python
- **Time:** 5-6 hours
- **What you build:** Track Windows registry changes for persistence mechanism detection
- **What you learn:** Windows registry structure, persistence techniques, change detection
- **Key skills:** Windows API (winreg), filesystem monitoring, baseline comparison
- **Prerequisites:** CS-08 (file integrity concepts)

---

## Phase B3: Offensive Security Basics (Intermediate)
**Core concepts:** Reverse shells, exploitation, web vulnerabilities, password attacks
**Estimated time:** 4-5 months
**Systems track synergy:** Pairs with Tier 3 (compilation) and Tier 4 (networking)

### Project B21 (CS-21): Keylogger
- **Source:** Repo -- PROJECTS/beginner/keylogger/ (IMPLEMENTED)
- **Language:** Python
- **Time:** 4-5 hours
- **What you build:** Keyboard event capture tool with timestamps for ethical testing
- **What you learn:** Input event handling, ethical hacking principles, detection avoidance concepts (for defense)
- **Key skills:** pynput, event-driven programming, file logging
- **Prerequisites:** Phase B2 complete
- **CRITICAL:** Ethical use only -- authorized testing environments only

### Project B22 (CS-22): Reverse Shell Handler
- **Source:** Repo -- SYNOPSES/intermediate/ (blueprint)
- **Language:** Go
- **Time:** 2-4 days
- **What you build:** Multi-client reverse shell server with file transfer, session management
- **What you learn:** Reverse shell mechanics, C2 basics, network pivoting, session handling
- **Key skills:** Go networking, goroutines, TLS encryption, multiplexing
- **Prerequisites:** CS-11, CS-21
- **Systems synergy:** Directly leverages Tier 4 networking knowledge
- **CRITICAL:** Authorized pentesting/CTF/lab environments only

### Project B23 (CS-23): Web Vulnerability Scanner
- **Source:** Repo -- SYNOPSES/intermediate/ (blueprint)
- **Language:** Python
- **Time:** 3-5 days
- **What you build:** Automated scanner for XSS, SQLi, CSRF with plugin architecture
- **What you learn:** OWASP Top 10, injection attacks, input validation, crawling
- **Key skills:** HTTP fuzzing, payload generation, plugin systems, report generation
- **Prerequisites:** CS-11, CS-13

### Project B24 (CS-24): Password Policy Auditor
- **Source:** Repo -- SYNOPSES/intermediate/ (blueprint)
- **Language:** Python
- **Time:** 2-4 days
- **What you build:** Audit password policies, test password strength, check for leaked credentials
- **What you learn:** Password entropy, common attack patterns, Have I Been Pwned API, policy compliance
- **Key skills:** Hash comparison, API integration, policy engine design
- **Prerequisites:** CS-03 (hash cracker)

### Project B25 (CS-25): Active Directory Enumeration
- **Source:** Repo -- SYNOPSES/intermediate/ (blueprint)
- **Language:** Python
- **Time:** 2-4 days
- **What you build:** Enumerate AD infrastructure: users, groups, GPOs, trusts, SPNs via LDAP
- **What you learn:** Active Directory structure, LDAP protocol, Kerberos basics, privilege mapping
- **Key skills:** ldap3 library, Kerberoasting detection, ACL analysis
- **Prerequisites:** CS-12 (DNS), CS-17 (SSH detection concepts)

### Project B26 (CS-26): Privilege Escalation Finder
- **Source:** Repo -- SYNOPSES/intermediate/ (blueprint)
- **Language:** Python
- **Time:** 2-4 days
- **What you build:** Identify SUID binaries, weak permissions, cron jobs, escalation paths on Linux
- **What you learn:** Linux privilege model, SUID/SGID, capability abuse, GTFOBins concepts
- **Key skills:** System enumeration, permission analysis, path finding algorithms
- **Prerequisites:** CS-20 (registry/system monitoring concepts), CS-25

### Project B27 (CS-27): OSINT Reconnaissance Framework
- **Source:** Repo -- SYNOPSES/intermediate/ (blueprint)
- **Language:** Python
- **Time:** 3-5 days
- **What you build:** Aggregate open-source intelligence: domain WHOIS, email discovery, social media, Shodan
- **What you learn:** OSINT methodologies, data correlation, target profiling, API aggregation
- **Key skills:** Multiple API integrations, data normalization, graph relationships
- **Prerequisites:** CS-09 (news scraper), CS-12 (DNS lookup)

### Project B28 (CS-28): OAuth Token Analyzer
- **Source:** Repo -- SYNOPSES/intermediate/ (blueprint)
- **Language:** Python
- **Time:** 2-4 days
- **What you build:** Decode, validate, and audit JWT/OAuth2 tokens for security weaknesses
- **What you learn:** JWT structure, OAuth2 flows, token vulnerabilities (alg:none, weak signing)
- **Key skills:** JWT parsing, signature verification, token replay detection
- **Prerequisites:** CS-02 (crypto basics), CS-23 (web vulnerability concepts)
- **Systems synergy:** Benefits from Tier 4 authentication server understanding

### Project B29 (CS-29): Binary Analysis Tool
- **Source:** Repo -- SYNOPSES/intermediate/ (blueprint)
- **Language:** Rust
- **Time:** 3-5 days
- **What you build:** Disassemble and analyze PE/ELF executables for malware indicators
- **What you learn:** Binary formats (PE/ELF), disassembly, import/export analysis, entropy analysis
- **Key skills:** Rust development, binary parsing, instruction decoding, pattern matching
- **Prerequisites:** CS-03 (hash cracker for entropy)
- **Systems synergy:** Directly leverages Tier 2 disassembler and Tier 3 compiler knowledge

### Project B30 (CS-30): Wireless Deauth Detector
- **Source:** Repo -- SYNOPSES/intermediate/ (blueprint)
- **Language:** Rust
- **Time:** 2-4 days
- **What you build:** Monitor WiFi for deauthentication attacks (common in WiFi cracking)
- **What you learn:** 802.11 management frames, deauth attacks, WIDS concepts
- **Key skills:** Rust networking, raw socket capture, frame parsing, alerting
- **Prerequisites:** CS-15 (WiFi scanner), CS-16 (ARP detection)

---

## Phase B4: Defensive Security & Monitoring (Intermediate)
**Core concepts:** SIEM, threat intelligence, intrusion detection, DDoS mitigation
**Estimated time:** 5-6 months
**Systems track synergy:** Pairs with Tier 5 (data systems) and Tier 6 (containerization)

### Project B31 (CS-31): Threat Intelligence Aggregator
- **Source:** Repo -- SYNOPSES/intermediate/ (blueprint)
- **Language:** Python
- **Time:** 2-4 days
- **What you build:** Collect and enrich IOCs (Indicators of Compromise) from multiple threat feeds
- **What you learn:** STIX/TAXII, threat feeds, IOC enrichment, threat scoring
- **Key skills:** API aggregation, data normalization, IOC correlation, feed management
- **Prerequisites:** CS-09 (news scraper), CS-18 (vulnerability scanner)

### Project B32 (CS-32): Network Intrusion Prevention System
- **Source:** Repo -- SYNOPSES/intermediate/ (blueprint)
- **Language:** Python
- **Time:** 3-5 days
- **What you build:** Real-time packet inspection with Snort-compatible rule engine and auto-blocking
- **What you learn:** IDS/IPS concepts, Snort rules, deep packet inspection, automated response
- **Key skills:** Packet processing, rule parsing, iptables integration, real-time alerting
- **Prerequisites:** CS-13 (traffic analyzer), CS-17 (brute force detector)
- **Systems synergy:** Benefits from Tier 4 TCP/IP stack understanding

### Project B33 (CS-33): Network Baseline Monitor
- **Source:** Repo -- SYNOPSES/intermediate/ (blueprint)
- **Language:** Python
- **Time:** 2-4 days
- **What you build:** Establish network traffic baselines and detect anomalies using statistical methods
- **What you learn:** Baseline modeling, statistical anomaly detection, time-series analysis
- **Key skills:** Traffic statistics, deviation detection, visualization, threshold management
- **Prerequisites:** CS-13, CS-32

### Project B34 (CS-34): DDoS Mitigation Tool
- **Source:** Repo -- SYNOPSES/intermediate/ (blueprint)
- **Language:** Go
- **Time:** 2-4 days
- **What you build:** Detect traffic spikes, classify attack types, apply rate limiting and IP blocking
- **What you learn:** DDoS attack types (volumetric, protocol, application), mitigation strategies
- **Key skills:** Go concurrency, traffic classification, rate limiting, firewall integration
- **Prerequisites:** CS-32, CS-33

### Project B35 (CS-35): SIEM Dashboard
- **Source:** Repo -- PROJECTS/intermediate/siem-dashboard/ (IMPLEMENTED)
- **Language:** Python (Flask) + TypeScript (React)
- **Time:** 3-5 days
- **What you build:** Full SIEM with log aggregation, correlation engine, alerting, rule management, attack simulation
- **What you learn:** SIEM architecture, log correlation, alert management, security event workflows
- **Key skills:** Full-stack development, SQLAlchemy, Redis, SCSS, real-time streaming
- **Components:** 221 files -- controllers, engine, models, services (backend); pages, components (frontend)
- **Prerequisites:** CS-31, CS-32, CS-33
- **Systems synergy:** Directly uses Tier 5 data systems (database, query) knowledge
- **Note:** This is the most substantial intermediate project -- production-quality SIEM

### Project B36 (CS-36): Web Application Firewall
- **Source:** Repo -- SYNOPSES/intermediate/ (blueprint)
- **Language:** Rust
- **Time:** 3-5 days
- **What you build:** Reverse proxy with request filtering, OWASP rule sets, rate limiting, logging
- **What you learn:** WAF architecture, rule-based filtering, HTTP normalization, evasion detection
- **Key skills:** Rust HTTP, proxy design, regex rule engine, logging pipeline
- **Prerequisites:** CS-23 (web vuln scanner), CS-34 (DDoS mitigation)
- **Systems synergy:** Benefits from Tier 4 reverse proxy knowledge

### Project B37 (CS-37): Docker Security Audit
- **Source:** Repo -- PROJECTS/intermediate/docker-security-audit/ (IMPLEMENTED)
- **Language:** Go
- **Time:** 1-2 days
- **What you build:** CIS Docker Benchmark scanner auditing containers, images, Dockerfiles, compose files, daemon config
- **What you learn:** CIS benchmarks, container security best practices, Docker API internals
- **Key skills:** Docker API, Go, YAML rule definitions, multi-format report generation (JSON/text/HTML)
- **Components:** 83 files -- analyzers, models, rules engine, output formatters
- **Prerequisites:** CS-18 (vulnerability scanner)
- **Systems synergy:** Directly uses Tier 6 container runtime knowledge

### Project B38 (CS-38): Container Security Scanner
- **Source:** Repo -- SYNOPSES/intermediate/ (blueprint)
- **Language:** Go + Docker
- **Time:** 1-2 days
- **What you build:** Scan Docker images for OS vulnerabilities, misconfigurations, secrets, compliance violations
- **What you learn:** Image layer analysis, vulnerability databases, secrets detection, compliance scanning
- **Key skills:** Docker image extraction, layer analysis, Trivy/Grype concepts
- **Prerequisites:** CS-37

### Project B39 (CS-39): Backup Integrity Checker
- **Source:** Repo -- SYNOPSES/intermediate/ (blueprint)
- **Language:** Python
- **Time:** 3-5 days
- **What you build:** Verify backup integrity with checksums, test restoration, schedule validation
- **What you learn:** Backup strategies, integrity verification, disaster recovery concepts
- **Key skills:** Hash verification, scheduled tasks, restoration testing, reporting
- **Prerequisites:** CS-08 (file integrity monitor)

### Project B40 (CS-40): Cloud Asset Inventory
- **Source:** Repo -- SYNOPSES/intermediate/ (blueprint)
- **Language:** Python + AWS/Azure SDK
- **Time:** 1-2 days
- **What you build:** Discover and catalog cloud resources across AWS/Azure with drift detection
- **What you learn:** Cloud resource management, API enumeration, asset tracking, drift detection
- **Key skills:** boto3, Azure SDK, resource tagging, inventory reporting
- **Prerequisites:** CS-18 (vulnerability scanning concepts)

---

## Phase B5: Application & API Security (Intermediate-Advanced)
**Core concepts:** API testing, rate limiting, full-stack security platforms, mobile security
**Estimated time:** 5-6 months
**Systems track synergy:** Pairs with Tier 4 (API gateway, auth server) and Tier 5 (data systems)

### Project B41 (CS-41): API Security Scanner
- **Source:** Repo -- PROJECTS/intermediate/api-security-scanner/ (IMPLEMENTED)
- **Language:** Python (FastAPI) + TypeScript (React)
- **Time:** 3-5 days
- **What you build:** Enterprise API vulnerability scanner for REST, GraphQL, SOAP based on OWASP API Top 10
- **What you learn:** OWASP API Top 10, ML-based fuzzing, GraphQL introspection, SOAP testing
- **Key skills:** FastAPI, React, database migrations (Alembic), ML integration
- **Components:** 152 files -- full-stack with scanning services, frontend dashboard
- **Prerequisites:** CS-23 (web vuln scanner), CS-28 (OAuth analyzer)

### Project B42 (CS-42): API Rate Limiter
- **Source:** Repo -- PROJECTS/advanced/api-rate-limiter/ (IMPLEMENTED)
- **Language:** Python
- **Time:** 1 week
- **What you build:** Distributed rate limiting middleware (fastapi_420) with token bucket, sliding window, fixed window algorithms
- **What you learn:** Rate limiting algorithms, distributed systems, circuit breaker pattern, Redis
- **Key skills:** FastAPI middleware, Redis, algorithm implementation, Docker Compose
- **Components:** 61 files -- algorithms, defense, storage, middleware
- **Prerequisites:** CS-34 (DDoS mitigation concepts), CS-41
- **Systems synergy:** Directly leverages Tier 4 cache system (Redis) knowledge

### Project B43 (CS-43): Bug Bounty Platform
- **Source:** Repo -- PROJECTS/advanced/bug-bounty-platform/ (IMPLEMENTED)
- **Language:** Python (FastAPI) + TypeScript (React)
- **Time:** 2-3 weeks
- **What you build:** Full vulnerability disclosure platform (like HackerOne) with CVSS scoring, program management, submission workflows
- **What you learn:** CVSS scoring, workflow state machines, RBAC, repository pattern, enterprise architecture
- **Key skills:** FastAPI, React, PostgreSQL, Alembic, Docker, role-based access
- **Components:** 247 files -- admin, auth, programs, submissions, users (backend); full React frontend
- **Prerequisites:** CS-41, CS-42
- **Note:** Largest project in the entire repo -- production-scale platform

### Project B44 (CS-44): Mobile App Security Analyzer
- **Source:** Repo -- SYNOPSES/intermediate/ (blueprint)
- **Language:** Python
- **Time:** 3-5 days
- **What you build:** Decompile and analyze APK/IPA files per OWASP Mobile Top 10
- **What you learn:** OWASP Mobile Top 10, APK structure, IPA analysis, binary protections
- **Key skills:** APK decompilation (jadx/apktool), static analysis, secrets detection, permission analysis
- **Prerequisites:** CS-29 (binary analysis), CS-23 (web vuln scanning)
- **iOS relevance:** Critical for the capstone iOS app security

### Project B45 (CS-45): Encrypted P2P Chat
- **Source:** Repo -- PROJECTS/advanced/encrypted-p2p-chat/ (IMPLEMENTED)
- **Language:** Python (FastAPI) + TypeScript (SolidJS)
- **Time:** 1-2 weeks
- **What you build:** End-to-end encrypted messaging with Signal Protocol (X3DH + Double Ratchet), WebAuthn passwordless auth
- **What you learn:** Signal Protocol, X3DH key exchange, Double Ratchet algorithm, WebAuthn/FIDO2
- **Key skills:** Cryptographic protocol implementation, WebSockets, multi-database (PostgreSQL + Redis + SurrealDB)
- **Components:** 190 files -- full Signal Protocol implementation + passkey authentication
- **Prerequisites:** CS-10 (encryption basics), CS-19 (TLS), CS-28 (OAuth/auth)
- **Systems synergy:** Leverages Tier 2 encryption and Tier 4 networking knowledge

### Project B46 (CS-46): Blockchain Smart Contract Auditor
- **Source:** Repo -- SYNOPSES/advanced/ (blueprint)
- **Language:** Python + Solidity
- **Time:** 3-4 weeks
- **What you build:** Static analysis tool for Solidity smart contracts detecting reentrancy, overflow, access control bugs
- **What you learn:** Smart contract vulnerabilities, Solidity bytecode, static analysis techniques
- **Key skills:** AST analysis, control flow graphs, Solidity patterns, vulnerability classification
- **Prerequisites:** CS-29 (binary analysis), CS-23 (vulnerability scanning)
- **Systems synergy:** Benefits from Tier 10 blockchain knowledge

### Project B47 (CS-47): Supply Chain Security Analyzer
- **Source:** Repo -- SYNOPSES/advanced/ (blueprint)
- **Language:** Go
- **Time:** 2-3 weeks
- **What you build:** Analyze dependency trees for vulnerabilities, typosquatting, malicious packages
- **What you learn:** Supply chain attacks, dependency analysis, package integrity, SBOM analysis
- **Key skills:** Package registry APIs, graph analysis, SBOM standards, risk scoring
- **Prerequisites:** CS-18 (vulnerability scanner), CS-38 (container scanning)

### Project B48 (CS-48): Cloud Security Posture Management
- **Source:** Repo -- SYNOPSES/advanced/ (blueprint)
- **Language:** Go + AWS/Azure/GCP SDK
- **Time:** 2-3 weeks
- **What you build:** Multi-cloud misconfiguration scanner checking CIS benchmarks across AWS, Azure, GCP
- **What you learn:** Cloud security best practices, CIS cloud benchmarks, multi-cloud architecture
- **Key skills:** Cloud provider SDKs, policy-as-code, compliance reporting, remediation
- **Prerequisites:** CS-37 (Docker audit), CS-40 (cloud inventory)

---

## Phase B6: Cloud, Container & Infrastructure Security (Advanced)
**Core concepts:** Advanced container security, Haskell networking, HSM, covert channels
**Estimated time:** 5-6 months
**Systems track synergy:** Pairs with Tier 6 (containerization), Tier 7 (OS)

### Project B49 (CS-49): Aenebris -- Haskell Reverse Proxy / WAF
- **Source:** Repo -- PROJECTS/advanced/Aenebris/ (IMPLEMENTED)
- **Language:** Haskell
- **Time:** 3-4 weeks
- **What you build:** High-performance reverse proxy with WAF, HTTP/2+3 support, ML bot detection, DDoS mitigation
- **What you learn:** Haskell networking, functional programming for systems, HTTP/2+3 protocols, WAF design
- **Key skills:** Haskell, Cabal, TLS/SSL, load balancing, Lua scripting integration
- **Components:** 56 files + whitepaper + 11 research documents
- **Prerequisites:** CS-36 (WAF basics), CS-34 (DDoS mitigation)
- **Systems synergy:** Directly leverages Tier 4 reverse proxy/load balancer knowledge

### Project B50 (CS-50): Hardware Security Module Emulator
- **Source:** Repo -- SYNOPSES/advanced/ (blueprint)
- **Language:** C
- **Time:** 2-3 weeks
- **What you build:** Software HSM with PKCS#11 interface for key generation, storage, and crypto operations
- **What you learn:** HSM architecture, PKCS#11 standard, key management, hardware security concepts
- **Key skills:** C development, cryptographic implementations, interface standards, secure memory
- **Prerequisites:** CS-45 (encryption protocols), CS-10 (encryption basics)
- **Systems synergy:** Benefits from Tier 2 memory allocator (secure memory management)

### Project B51 (CS-51): Network Covert Channel
- **Source:** Repo -- SYNOPSES/advanced/ (blueprint)
- **Language:** Rust
- **Time:** 3-4 weeks
- **What you build:** Data exfiltration via covert network channels (DNS tunneling, ICMP, TCP timing)
- **What you learn:** Covert channel theory, DNS tunneling, protocol abuse, data encoding in headers
- **Key skills:** Raw socket programming, protocol manipulation, timing channels, steganography
- **Prerequisites:** CS-13 (traffic analysis), CS-22 (reverse shell)
- **Systems synergy:** Leverages Tier 4 TCP/IP stack deep knowledge
- **CRITICAL:** Authorized environments only -- for understanding detection

### Project B52 (CS-52): Kernel Rootkit Detection
- **Source:** Repo -- SYNOPSES/advanced/ (blueprint)
- **Language:** Rust
- **Time:** 2-3 weeks
- **What you build:** Detect kernel-level rootkits through memory forensics, syscall table verification, module analysis
- **What you learn:** Kernel internals, rootkit techniques (syscall hooking, DKOM), memory forensics
- **Key skills:** /proc and /sys analysis, syscall tracing, kernel module inspection, memory scanning
- **Prerequisites:** CS-29 (binary analysis), CS-26 (privilege escalation)
- **Systems synergy:** Directly leverages Tier 7 OS kernel knowledge

### Project B53 (CS-53): Exploit Development Framework
- **Source:** Repo -- SYNOPSES/advanced/ (blueprint)
- **Language:** C++
- **Time:** 3-4 weeks
- **What you build:** Modular exploitation framework with payload generation, encoding, and delivery
- **What you learn:** Buffer overflow, ROP chains, shellcode, payload encoding, exploitation methodology
- **Key skills:** C++ memory manipulation, assembly, binary exploitation, modular architecture
- **Prerequisites:** CS-29 (binary analysis), CS-22 (reverse shell), CS-52 (kernel knowledge)
- **Systems synergy:** Leverages Tier 2 (memory allocator), Tier 3 (compiler), Tier 7 (OS) knowledge
- **CRITICAL:** Authorized pentesting/CTF only

### Project B54 (CS-54): Zero Day Vulnerability Scanner
- **Source:** Repo -- SYNOPSES/advanced/ (blueprint)
- **Language:** Rust + C
- **Time:** 2-3 weeks
- **What you build:** Coverage-guided fuzzer for discovering unknown vulnerabilities in binaries
- **What you learn:** Fuzzing theory (AFL/libFuzzer), coverage instrumentation, crash triage, reproducibility
- **Key skills:** Rust systems programming, code coverage, mutation strategies, crash analysis
- **Prerequisites:** CS-29 (binary analysis), CS-53 (exploit framework)
- **Systems synergy:** Leverages Tier 3 compiler knowledge (instrumentation)

---

## Phase B7: Advanced Offensive Security (Advanced)
**Core concepts:** APT simulation, automated pentesting, distributed cracking, adversarial ML
**Estimated time:** 5-6 months
**Systems track synergy:** Pairs with Tier 10 (distributed systems), Tier 11 (ML)

### Project B55 (CS-55): Advanced Persistent Threat Simulator
- **Source:** Repo -- SYNOPSES/advanced/ (blueprint)
- **Language:** Go
- **Time:** 3-4 weeks
- **What you build:** Multi-stage APT simulation with C2 infrastructure, lateral movement, data exfiltration
- **What you learn:** APT lifecycle (MITRE ATT&CK), C2 frameworks, lateral movement, persistence
- **Key skills:** Go networking, encryption, multi-stage operations, evasion techniques (for detection)
- **Prerequisites:** CS-22 (reverse shell), CS-25 (AD enumeration), CS-51 (covert channels)
- **CRITICAL:** Authorized red team exercises only

### Project B56 (CS-56): Automated Penetration Testing
- **Source:** Repo -- SYNOPSES/advanced/ (blueprint)
- **Language:** Python
- **Time:** 3-4 weeks
- **What you build:** Full pentest automation from recon to exploitation to reporting
- **What you learn:** Pentest methodology, automation orchestration, finding chaining, report generation
- **Key skills:** Tool integration (nmap, nikto, etc.), workflow orchestration, finding correlation
- **Prerequisites:** CS-27 (OSINT), CS-23 (web vuln scanner), CS-53 (exploit framework)

### Project B57 (CS-57): Distributed Password Cracker
- **Source:** Repo -- SYNOPSES/advanced/ (blueprint)
- **Language:** C++ + CUDA
- **Time:** 3-4 weeks
- **What you build:** GPU-accelerated distributed hash cracking with work distribution and rule engine
- **What you learn:** GPU programming (CUDA), distributed computing, hash algorithms, work scheduling
- **Key skills:** CUDA kernels, distributed coordination, hash algorithm optimization, rule-based generation
- **Prerequisites:** CS-03 (hash cracker), CS-24 (password auditing)
- **Systems synergy:** Leverages Tier 10 distributed systems and Tier 8 GPU concepts

### Project B58 (CS-58): Adversarial ML Attacker
- **Source:** Repo -- SYNOPSES/advanced/ (blueprint)
- **Language:** Python + TensorFlow
- **Time:** 3-4 weeks
- **What you build:** Generate adversarial examples (FGSM, PGD, DeepFool, C&W) to test ML model robustness
- **What you learn:** Adversarial ML theory, attack methods, model robustness, defense evaluation
- **Key skills:** TensorFlow/PyTorch, gradient manipulation, perturbation generation, model evaluation
- **Prerequisites:** Phase B8 CS-61 (AI Threat Detection) or ML fundamentals
- **Systems synergy:** Directly leverages Tier 11 ML framework knowledge

### Project B59 (CS-59): Quantum Resistant Encryption
- **Source:** Repo -- SYNOPSES/advanced/ (blueprint)
- **Language:** Python
- **Time:** 3-4 weeks
- **What you build:** Post-quantum cryptography implementations: Kyber (KEM), Dilithium (signatures), SPHINCS+
- **What you learn:** Lattice-based cryptography, post-quantum algorithms, NIST PQC standards
- **Key skills:** Polynomial arithmetic, NTT transforms, lattice operations, security proofs
- **Prerequisites:** CS-45 (encrypted chat/crypto protocols), CS-50 (HSM)
- **Systems synergy:** Benefits from Tier 2 encryption and Tier 10 cryptography knowledge

### Project B60 (CS-60): Malware Analysis Platform
- **Source:** Repo -- SYNOPSES/advanced/ (blueprint)
- **Language:** Rust + Docker
- **Time:** 2-3 weeks
- **What you build:** Automated sandbox for malware analysis with YARA rules, IOC extraction, behavioral analysis
- **What you learn:** Malware behavior, sandbox design, YARA rules, IOC extraction, behavioral signatures
- **Key skills:** Rust, Docker isolation, process monitoring, network interception, YARA rule writing
- **Prerequisites:** CS-29 (binary analysis), CS-37 (Docker security), CS-52 (rootkit detection)
- **Systems synergy:** Leverages Tier 6 container runtime and Tier 7 OS kernel knowledge

---

## Phase B8: AI/ML Security & Advanced Defense (Advanced)
**Core concepts:** AI-powered threat detection, autonomous SOC, ML security
**Estimated time:** 6-8 months
**Systems track synergy:** Directly pairs with Tier 11 (ML framework)

### Project B61 (CS-61): AI Threat Detection
- **Source:** Repo -- SYNOPSES/advanced/ (blueprint, currently being built in the repo)
- **Language:** Python + TensorFlow
- **Time:** 3-4 weeks
- **What you build:** ML-based network traffic classification with anomaly detection and threat categorization
- **What you learn:** ML for security, feature engineering from network data, model training, real-time inference
- **Key skills:** TensorFlow, scikit-learn, feature extraction, model evaluation, streaming inference
- **Prerequisites:** CS-13 (traffic analysis), CS-33 (baseline monitor), ML fundamentals

### Project B62 (CS-62): Autonomous Security Operations Center
- **Source:** Repo -- SYNOPSES/advanced/ (blueprint)
- **Language:** Python + Multiple
- **Time:** 4-6 weeks
- **What you build:** Full autonomous SOC with ML-driven decision making, automated triage, incident response
- **What you learn:** SOC automation, decision trees, alert fatigue reduction, autonomous response
- **Key skills:** ML orchestration, alert correlation, playbook automation, decision engine
- **Prerequisites:** CS-35 (SIEM), CS-61 (AI threat detection), CS-31 (threat intelligence)
- **Note:** This is the most complex individual project -- integrates nearly all prior knowledge

### Projects B63-B66: Capstone iOS App Components (see Phase B9 below)

---

## Phase B9: Capstone -- All-in-One AI Cybersecurity iOS Platform
**The final phase -- building the unified iOS application**
**Estimated time:** 6-12 months
**Systems track synergy:** Integrates knowledge from ALL tiers

This phase takes the knowledge and implementations from all 60 cybersecurity projects plus systems engineering understanding and consolidates them into a single, unified iOS application.

### Architecture: CyberShield AI (Working Name)

**Platform:** iOS (Swift/SwiftUI) with Python/Go microservice backends
**AI Engine:** On-device CoreML + Cloud-based Claude API for advanced analysis
**Design Philosophy:** Mobile-first security operations center in your pocket

### Project B63 (CS-63): iOS Core Framework & Security Scanner Module
- **Time:** 4-6 weeks
- **What you build:** Core iOS app shell with integrated network scanner, port scanner, DNS lookup, vulnerability scanner
- **Modules integrated from:** CS-11 (port scanner), CS-12 (DNS lookup), CS-13 (traffic analyzer), CS-18 (vuln scanner), CS-19 (TLS scanner)
- **Technologies:** Swift, SwiftUI, Network.framework, CoreML
- **Key features:**
  - Network discovery and scanning
  - Port scanning with service detection
  - DNS enumeration
  - SSL/TLS certificate analysis
  - Vulnerability checking against CVE databases
  - On-device result caching and history

### Project B64 (CS-64): AI Threat Detection & SIEM Mobile Module
- **Time:** 4-6 weeks
- **What you build:** Mobile SIEM dashboard with AI-powered threat detection and real-time alerting
- **Modules integrated from:** CS-35 (SIEM), CS-61 (AI threat detection), CS-31 (threat intel), CS-33 (baseline monitor)
- **Technologies:** Swift, CoreML, CloudKit, Push Notifications
- **Key features:**
  - Real-time log aggregation from connected systems
  - On-device ML threat classification (CoreML)
  - Push notification alerting
  - Threat intelligence feed integration
  - Network baseline monitoring
  - Interactive dashboard with charts (SwiftUI Charts)

### Project B65 (CS-65): Offensive Security Toolkit Module
- **Time:** 4-6 weeks
- **What you build:** Authorized pentesting toolkit with web scanner, OSINT, and reporting
- **Modules integrated from:** CS-23 (web vuln scanner), CS-27 (OSINT), CS-28 (OAuth analyzer), CS-44 (mobile analyzer)
- **Technologies:** Swift, WKWebView, CryptoKit
- **Key features:**
  - Web application scanning (XSS, SQLi detection)
  - OSINT reconnaissance tools
  - JWT/OAuth token analysis
  - Phishing URL detection
  - Encrypted notes and findings management
  - PDF report generation
  - **Authorization verification required before tool use**

### Project B66 (CS-66): Encrypted Communication & Cloud Security Module
- **Time:** 4-6 weeks
- **What you build:** Secure communications hub with E2EE messaging, cloud posture management, and API security testing
- **Modules integrated from:** CS-45 (encrypted chat), CS-48 (cloud security), CS-41 (API scanner), CS-42 (rate limiter)
- **Technologies:** Swift, CryptoKit, CloudKit, WebSocket
- **Key features:**
  - End-to-end encrypted messaging (Signal Protocol via CryptoKit)
  - Cloud security posture dashboard (AWS/Azure/GCP)
  - API endpoint security testing
  - Rate limit testing tools
  - Secure file sharing
  - Biometric authentication (Face ID / Touch ID)

---

# Cross-Track Dependency Map

## How Systems Engineering Feeds Cybersecurity

| Systems Project | Enables Cybersecurity Projects |
|----------------|-------------------------------|
| Memory allocator (Tier 1) | Exploit framework, rootkit detection |
| Encryption algorithm (Tier 2) | All crypto projects (CS-02 through CS-59) |
| File system (Tier 2) | File integrity monitor, malware sandbox |
| Disassembler (Tier 2) | Binary analysis, exploit development |
| Compiler (Tier 3) | Fuzzing, binary analysis, code instrumentation |
| TCP/IP stack (Tier 4) | All network security projects |
| Web server (Tier 4) | WAF, API security, web vulnerability scanning |
| Reverse proxy (Tier 4) | Aenebris WAF, API gateway security |
| Auth server (Tier 4) | OAuth analyzer, encrypted chat |
| Cache system (Tier 4) | API rate limiter (Redis) |
| Database (Tier 5) | SIEM, bug bounty platform, all full-stack projects |
| Container runtime (Tier 6) | Docker security audit, container scanning, malware sandbox |
| OS kernel (Tier 7) | Kernel rootkit detection, privilege escalation |
| Blockchain (Tier 10) | Smart contract auditor |
| ML framework (Tier 11) | AI threat detection, adversarial ML, autonomous SOC |

## How Cybersecurity Feeds Systems Engineering

| Cybersecurity Project | Enhances Systems Understanding |
|----------------------|-------------------------------|
| Port scanner (CS-11) | Practical TCP/IP knowledge for Tier 4 |
| Traffic analyzer (CS-13) | Protocol internals for networking stack |
| Encryption projects (CS-02, CS-45) | Applied crypto for Tier 2 encryption, Tier 10 |
| Binary analysis (CS-29) | Practical disassembly for Tier 2 |
| WAF (CS-36, CS-49) | Reverse proxy architecture for Tier 4 |
| Rootkit detection (CS-52) | Kernel internals for Tier 7 OS |
| Distributed cracker (CS-57) | GPU programming for Tier 8, distributed systems for Tier 10 |

---

# Recommended Learning Path (Interleaved Tracks)

## Year 1: Foundations (Months 1-12)
- **Systems:** Tier 1 (foundational tools) + Tier 2 (low-level systems)
- **Cyber:** Phase B1 (security fundamentals) + Phase B2 (network security)
- **Interleave:** Build encryption algorithm (Tier 2) alongside Caesar cipher/hash cracker (B1)
- **Interleave:** Build TCP/IP concepts while building port scanner and traffic analyzer

## Year 2: Core Systems & Offensive Basics (Months 13-24)
- **Systems:** Tier 3 (compilation) + Tier 4 (networking)
- **Cyber:** Phase B3 (offensive basics) + Phase B4 (defensive monitoring)
- **Interleave:** Build web server (Tier 4) alongside web vulnerability scanner (B3)
- **Interleave:** Build auth server while studying OAuth and encrypted chat

## Year 3: Advanced Infrastructure (Months 25-36)
- **Systems:** Tier 5 (data systems) + Tier 6 (containerization) + Tier 7 (OS)
- **Cyber:** Phase B5 (app/API security) + Phase B6 (infrastructure security)
- **Interleave:** Build database while building SIEM dashboard
- **Interleave:** Build container runtime alongside Docker security audit

## Year 4: Advanced Specialization (Months 37-48)
- **Systems:** Tier 8-9 (graphics, browser) + Tier 10 (distributed)
- **Cyber:** Phase B7 (advanced offensive) + Phase B8 (AI/ML security)
- **Interleave:** Build ML framework (Tier 11) alongside AI threat detection

## Year 5: Capstone (Months 49-60)
- **Systems:** Tier 10-11 completion
- **Cyber:** Phase B9 (iOS capstone app)
- **Build:** CyberShield AI iOS platform integrating everything

---

# iOS Capstone App: CyberShield AI

## High-Level Architecture

```
CyberShield AI (iOS)
├── Core Framework (Swift/SwiftUI)
│   ├── Authentication (Face ID, passkeys)
│   ├── Local Database (SwiftData/CoreData)
│   ├── Networking Layer (URLSession, WebSocket)
│   └── CoreML Engine (on-device inference)
│
├── Scanner Module
│   ├── Network Scanner
│   ├── Port Scanner
│   ├── DNS Lookup
│   ├── TLS/SSL Analyzer
│   ├── Vulnerability Checker
│   └── WiFi Analyzer
│
├── SIEM Module
│   ├── Log Aggregator
│   ├── Correlation Engine
│   ├── Alert Dashboard
│   ├── Threat Intel Feed
│   └── Baseline Monitor
│
├── AI Engine
│   ├── CoreML Threat Classifier
│   ├── Anomaly Detector
│   ├── NLP Log Analyzer
│   ├── Claude API Integration (advanced queries)
│   └── On-device Feature Extraction
│
├── Pentest Toolkit
│   ├── Web Scanner
│   ├── OSINT Tools
│   ├── Token Analyzer
│   ├── Phishing Detector
│   └── Report Generator
│
├── Secure Comms
│   ├── E2EE Messaging (Signal Protocol)
│   ├── Secure File Sharing
│   ├── Encrypted Notes
│   └── Team Collaboration
│
├── Cloud Security
│   ├── AWS Posture Check
│   ├── Azure Posture Check
│   ├── GCP Posture Check
│   └── Multi-cloud Dashboard
│
└── Backend Services (Microservices)
    ├── FastAPI (Python) -- ML inference, scanning orchestration
    ├── Go Service -- High-performance scanning, C2 simulation
    └── Redis/PostgreSQL -- Data persistence, caching
```

## Technology Stack for iOS App

| Layer | Technology |
|-------|-----------|
| Frontend | SwiftUI, Swift Charts, MapKit |
| Local AI | CoreML, Create ML, Natural Language |
| Networking | Network.framework, URLSession, Starscream (WebSocket) |
| Security | CryptoKit, Security.framework, LocalAuthentication |
| Storage | SwiftData, Keychain, CloudKit |
| Backend | FastAPI (Python), Go microservices |
| AI Cloud | Claude API (Anthropic), custom ML models |
| Database | PostgreSQL, Redis |
| Deployment | Docker, Kubernetes |

## Key Design Principles

1. **On-device first:** All sensitive analysis happens on-device when possible
2. **Zero-trust:** All communications encrypted, all inputs validated
3. **Authorization-gated:** Offensive tools require explicit authorization verification
4. **Modular:** Each security module is independently deployable
5. **Offline-capable:** Core scanning works without internet
6. **Accessible:** WCAG 2.1 AA compliance for all interfaces

---

# Certification Alignment

The repo includes 10 career certification roadmaps. Projects map to certifications:

| Certification Path | Aligned Projects |
|-------------------|-----------------|
| SOC Analyst | CS-35 (SIEM), CS-31 (threat intel), CS-33 (baseline), CS-61 (AI detection) |
| Penetration Tester | CS-11 (port scan), CS-23 (web vuln), CS-53 (exploit), CS-56 (auto pentest) |
| Security Engineer | CS-36 (WAF), CS-42 (rate limiter), CS-49 (Aenebris), CS-48 (CSPM) |
| Security Architect | CS-45 (E2EE), CS-50 (HSM), CS-59 (PQC), CS-62 (SOC) |
| GRC Analyst | CS-37 (Docker audit), CS-39 (backup), CS-48 (cloud posture) |
| Incident Responder | CS-35 (SIEM), CS-60 (malware analysis), CS-52 (rootkit detection) |
| Cloud Security Engineer | CS-40 (cloud inventory), CS-48 (CSPM), CS-38 (container scan) |
| Application Security | CS-23 (web vuln), CS-41 (API scanner), CS-44 (mobile), CS-46 (smart contract) |
| Threat Intelligence | CS-31 (threat intel), CS-27 (OSINT), CS-55 (APT simulator) |
| Network Engineer | CS-11-16 (all network projects), CS-32 (IPS), CS-34 (DDoS) |

---

# Progress Tracking Template

```
# Cybersecurity Track Progress

## Phase B1: Security Fundamentals
- [ ] CS-01: Base64 Encoder/Decoder
- [ ] CS-02: Caesar Cipher
- [ ] CS-03: Hash Cracker
- [ ] CS-04: Steganography Tool
- [ ] CS-05: Metadata Scrubber
- [ ] CS-06: Phishing URL Detector
- [ ] CS-07: Firewall Log Parser
- [ ] CS-08: File Integrity Monitor
- [ ] CS-09: Security News Scraper
- [ ] CS-10: Ransomware Simulator
Phase B1 Complete: [ ]

## Phase B2: Network Security & Reconnaissance
- [ ] CS-11: Simple Port Scanner
- [ ] CS-12: DNS Lookup CLI
- [ ] CS-13: Network Traffic Analyzer
- [ ] CS-14: MAC Address Spoofer
- [ ] CS-15: WiFi Network Scanner
- [ ] CS-16: ARP Spoofing Detector
- [ ] CS-17: SSH Brute Force Detector
- [ ] CS-18: Simple Vulnerability Scanner
- [ ] CS-19: SSL/TLS Certificate Scanner
- [ ] CS-20: Windows Registry Monitor
Phase B2 Complete: [ ]

## Phase B3: Offensive Security Basics
- [ ] CS-21: Keylogger
- [ ] CS-22: Reverse Shell Handler
- [ ] CS-23: Web Vulnerability Scanner
- [ ] CS-24: Password Policy Auditor
- [ ] CS-25: Active Directory Enumeration
- [ ] CS-26: Privilege Escalation Finder
- [ ] CS-27: OSINT Reconnaissance Framework
- [ ] CS-28: OAuth Token Analyzer
- [ ] CS-29: Binary Analysis Tool
- [ ] CS-30: Wireless Deauth Detector
Phase B3 Complete: [ ]

## Phase B4: Defensive Security & Monitoring
- [ ] CS-31: Threat Intelligence Aggregator
- [ ] CS-32: Network Intrusion Prevention
- [ ] CS-33: Network Baseline Monitor
- [ ] CS-34: DDoS Mitigation Tool
- [ ] CS-35: SIEM Dashboard
- [ ] CS-36: Web Application Firewall
- [ ] CS-37: Docker Security Audit
- [ ] CS-38: Container Security Scanner
- [ ] CS-39: Backup Integrity Checker
- [ ] CS-40: Cloud Asset Inventory
Phase B4 Complete: [ ]

## Phase B5: Application & API Security
- [ ] CS-41: API Security Scanner
- [ ] CS-42: API Rate Limiter
- [ ] CS-43: Bug Bounty Platform
- [ ] CS-44: Mobile App Security Analyzer
- [ ] CS-45: Encrypted P2P Chat
- [ ] CS-46: Blockchain Smart Contract Auditor
- [ ] CS-47: Supply Chain Security Analyzer
- [ ] CS-48: Cloud Security Posture Management
Phase B5 Complete: [ ]

## Phase B6: Cloud, Container & Infrastructure Security
- [ ] CS-49: Aenebris (Haskell Reverse Proxy/WAF)
- [ ] CS-50: Hardware Security Module Emulator
- [ ] CS-51: Network Covert Channel
- [ ] CS-52: Kernel Rootkit Detection
- [ ] CS-53: Exploit Development Framework
- [ ] CS-54: Zero Day Vulnerability Scanner
Phase B6 Complete: [ ]

## Phase B7: Advanced Offensive Security
- [ ] CS-55: APT Simulator
- [ ] CS-56: Automated Penetration Testing
- [ ] CS-57: Distributed Password Cracker
- [ ] CS-58: Adversarial ML Attacker
- [ ] CS-59: Quantum Resistant Encryption
- [ ] CS-60: Malware Analysis Platform
Phase B7 Complete: [ ]

## Phase B8: AI/ML Security
- [ ] CS-61: AI Threat Detection
- [ ] CS-62: Autonomous Security Operations Center
Phase B8 Complete: [ ]

## Phase B9: Capstone iOS App
- [ ] CS-63: iOS Core Framework & Scanner Module
- [ ] CS-64: AI Threat Detection & SIEM Mobile Module
- [ ] CS-65: Offensive Security Toolkit Module
- [ ] CS-66: Encrypted Communication & Cloud Security Module
Phase B9 Complete: [ ]

## Overall: [X]/66 projects complete
```

---

# Languages & Technologies Across All Projects

| Language | Project Count | Used In |
|----------|-------------|---------|
| Python | ~35 | Most beginner/intermediate, ML projects, FastAPI backends |
| Go | ~8 | Vuln scanner, Docker audit, DDoS, CSPM, APT, supply chain |
| TypeScript | ~5 | React/SolidJS frontends for full-stack projects |
| Rust | ~6 | WAF, deauth detector, binary analysis, rootkit, covert channel, malware sandbox |
| C++ | ~3 | Port scanner, exploit framework, distributed cracker (CUDA) |
| Haskell | 1 | Aenebris reverse proxy/WAF |
| C | 1 | HSM emulator |
| Bash | 1 | Firewall log parser |
| Swift | 4 | iOS capstone modules |
| Solidity | 1 | Smart contract auditor (target language) |

---

# What's Next

With both curricula defined:

1. **Start Phase B1** -- Begin with CS-01 (Base64 Encoder/Decoder) as the very first cybersecurity project
2. **Interleave with Systems Track** -- Work on Tier 1 systems projects alongside Phase B1
3. **Build incrementally** -- Each project builds skills for the next
4. **Track progress** -- Use the checklist above to monitor advancement
5. **Target the capstone** -- Every project is a building block for CyberShield AI

The 120-project combined curriculum creates a complete systems + security engineer capable of building the all-in-one AI cybersecurity iOS platform from scratch.
