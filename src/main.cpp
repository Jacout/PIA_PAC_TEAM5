#include "FileReader.h"
#include "HashGenerator.h"
#include "Sniffer.h"
#include "Logger.h"
#include "ProcessEnumerator.h"
#include <iostream>

int main(int argc, char* argv[]) {
    Logger logger("pia_team5.log");
    if (argc < 2) {
        std::cout << "Usage: pia_team5_debug <command> [args]\n"
                     "Commands: hash , sniff <interface>, processes, help\n";
        return 1;
    }
    std::string cmd = argv[1];
    if (cmd == "help") {
        std::cout << "Commands:\n"
                  << "  hash             Compute SHA256 of file (local)\n"
                  << "  sniff <interface>      Capture small number of packets (sudo required)\n"
                  << "  processes              List processes (reads /proc)\n"
                  << "  help                   Show this help\n";
        return 0;
    } else if (cmd == "hash") {
        if (argc < 3) {
            logger.error("hash requires a file path");
            return 2;
        }
        std::string path = argv[2];
        auto h = hashFromFile(path);
        if (h.empty()) {
            logger.error("Failed to read or hash file: " + path);
            return 3;
        }
        logger.info("SHA256(" + path + ") = " + h);
        return 0;
    } else if (cmd == "sniff") {
        if (argc < 3) {
            logger.error("sniff requires an interface name (e.g., lo)");
            return 4;
        }
        std::string iface = argv[2];
        logger.info("Starting controlled sniff on interface: " + iface);
        int rc = sniffInterface(iface, 10);
        if (rc != 0) logger.error("Sniffing failed or incomplete");
        return rc;
    } else if (cmd == "processes") {
        auto procs = listProcesses();
        for (auto &p : procs) {
            std::cout << p.first << ": " << p.second << "\n";
        }
        return 0;
    } else {
        logger.error("Unknown command. Use help.");
        return 5;
    }
}