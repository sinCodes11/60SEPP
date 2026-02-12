#include "ServiceDB.hpp"

// Comprehensive service database -- 80+ well-known ports.
// These are the default ports assigned by IANA and commonly
// seen during real-world network reconnaissance.
//
// WHY a static map instead of reading /etc/services?
//   - Portability: works on any OS without filesystem access
//   - Speed: no I/O at startup
//   - Predictability: always the same result
//   - We can still add file-loading later if needed

const std::unordered_map<uint16_t, std::string> ServiceDB::services{
    // File transfer
    {20,    "FTP-DATA"},
    {21,    "FTP"},
    {69,    "TFTP"},
    {115,   "SFTP"},

    // Remote access
    {22,    "SSH"},
    {23,    "TELNET"},
    {513,   "RLOGIN"},
    {3389,  "RDP"},
    {5900,  "VNC"},
    {5901,  "VNC-1"},
    {5902,  "VNC-2"},

    // Email
    {25,    "SMTP"},
    {110,   "POP3"},
    {143,   "IMAP"},
    {465,   "SMTPS"},
    {587,   "SMTP-SUBMISSION"},
    {993,   "IMAPS"},
    {995,   "POP3S"},

    // DNS
    {53,    "DNS"},
    {853,   "DNS-OVER-TLS"},
    {5353,  "MDNS"},

    // Web
    {80,    "HTTP"},
    {443,   "HTTPS"},
    {8080,  "HTTP-PROXY"},
    {8443,  "HTTPS-ALT"},
    {8000,  "HTTP-ALT"},
    {8888,  "HTTP-ALT-2"},
    {3000,  "DEV-SERVER"},
    {9090,  "WEB-CONSOLE"},

    // DHCP / Network infrastructure
    {67,    "DHCP-SERVER"},
    {68,    "DHCP-CLIENT"},
    {161,   "SNMP"},
    {162,   "SNMP-TRAP"},
    {514,   "SYSLOG"},
    {1900,  "SSDP/UPNP"},

    // Proxies & tunnels
    {1080,  "SOCKS"},
    {3128,  "SQUID-PROXY"},
    {8118,  "PRIVOXY"},
    {9050,  "TOR-SOCKS"},
    {9051,  "TOR-CONTROL"},

    // Databases
    {1433,  "MSSQL"},
    {1521,  "ORACLE-DB"},
    {3306,  "MYSQL"},
    {5432,  "POSTGRESQL"},
    {6379,  "REDIS"},
    {27017, "MONGODB"},
    {27018, "MONGODB-SHARD"},
    {5984,  "COUCHDB"},
    {9200,  "ELASTICSEARCH"},
    {9300,  "ELASTICSEARCH-TRANSPORT"},
    {11211, "MEMCACHED"},

    // Message queues & streaming
    {5672,  "AMQP/RABBITMQ"},
    {5671,  "AMQPS"},
    {9092,  "KAFKA"},
    {1883,  "MQTT"},
    {8883,  "MQTTS"},
    {6667,  "IRC"},
    {6697,  "IRC-TLS"},

    // Directory services
    {389,   "LDAP"},
    {636,   "LDAPS"},
    {88,    "KERBEROS"},

    // File sharing
    {445,   "SMB"},
    {139,   "NETBIOS-SSN"},
    {137,   "NETBIOS-NS"},
    {138,   "NETBIOS-DGM"},
    {111,   "RPCBIND"},
    {2049,  "NFS"},

    // Containers & orchestration
    {2375,  "DOCKER"},
    {2376,  "DOCKER-TLS"},
    {6443,  "KUBERNETES-API"},
    {10250, "KUBELET"},
    {2379,  "ETCD"},
    {8500,  "CONSUL"},

    // Monitoring
    {9100,  "NODE-EXPORTER"},
    {9090,  "PROMETHEUS"},
    {3000,  "GRAFANA"},
    {8086,  "INFLUXDB"},
    {161,   "SNMP"},

    // Other common
    {873,   "RSYNC"},
    {6660,  "IRC-ALT"},
    {4444,  "METASPLOIT"},
    {4443,  "PHAROS"},
    {1194,  "OPENVPN"},
    {1723,  "PPTP"},
    {500,   "ISAKMP/IKE"},
    {51820, "WIREGUARD"},
};

std::string ServiceDB::lookup(uint16_t port) {
    auto it = services.find(port);
    if (it != services.end()) {
        return it->second;
    }
    return "unknown";
}

const std::unordered_map<uint16_t, std::string>& ServiceDB::all() {
    return services;
}
