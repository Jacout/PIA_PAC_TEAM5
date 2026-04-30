#include <iostream>
#include <string>

#include "FileReader.h"
#include "HashGenerator.h"
#include "sniffer.h"

int main(int argc, char *argv[]) {

    if (argc < 2) {
        std::cout << "Uso:\n";
        std::cout << "  ./program hash <archivo>\n";
        std::cout << "  ./program sniff <interfaz>\n";
        return 1;
    }

    std::string modo = argv[1];

    // 🔹 MODO HASH
    if (modo == "hash") {
        if (argc != 3) {
            std::cerr << "Uso: ./program hash <archivo>\n";
            return 1;
        }

        std::string filepath = argv[2];

        auto data = readFile(filepath);

        if (data.empty()) {
            std::cerr << "Error leyendo archivo\n";
            return 1;
        }

        std::string hash = generateSHA256(data);

        std::cout << "File: " << filepath << "\n";
        std::cout << "SHA256: " << hash << "\n";
    }

    // 🔹 MODO SNIFFER
    else if (modo == "sniff") {
        if (argc != 3) {
            std::cerr << "Uso: ./program sniff <interfaz>\n";
            return 1;
        }

        Sniffer miSniffer(argv[2]);

        if (!miSniffer.captureSinglePacket()) {
            return 1;
        }
    }

    else {
        std::cerr << "Modo inválido\n";
        return 1;
    }

    return 0;
}
