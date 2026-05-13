#include "Sniffer.h"
#include <pcap/pcap.h>
#include <iostream>
#include <cstring>
#include <algorithm>

// Callback: muestra resumen por paquete, no payload completo.
static void packet_handler(u_char* user, const struct pcap_pkthdr* h, const u_char* bytes) {
    (void)user;
    std::cout << "Captured packet: len=" << h->len << " caplen=" << h->caplen << std::endl;
    size_t show = std::min<size_t>(h->caplen, 16);
    for (size_t i = 0; i < show; ++i) printf("%02x ", bytes[i]);
    printf("\n");
}

int sniffInterface(const std::string& interface, int packet_count) {
    char errbuf[PCAP_ERRBUF_SIZE];
    // No promiscuous to limit scope; timeout 1000ms.
    pcap_t* handle = pcap_open_live(interface.c_str(), 65535, 0, 1000, errbuf);
    if (!handle) {
        std::cerr << "pcap_open_live failed: " << errbuf << std::endl;
        return 1;
    }
    int res = pcap_loop(handle, packet_count, packet_handler, nullptr);
    if (res == -1) {
        std::cerr << "pcap_loop error: " << pcap_geterr(handle) << std::endl;
        pcap_close(handle);
        return 2;
    }
    pcap_close(handle);
    return 0;
}
