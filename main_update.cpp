#include "sniffer.h"
#include <iostream>

int main(int argc, char *argv[]) {
    // Validar que el usuario pase la interfaz de red como argumento
    if (argc != 2) {
        std::cerr << "Uso incorrecto." << std::endl;
        std::cerr << "Ejecución: " << argv[0] << " <interfaz_de_red>" << std::endl;
        std::cerr << "Ejemplo:   " << argv[0] << " lo" << std::endl;
        return 1;
    }

    Sniffer miSniffer(argv[1]);
    
    if (!miSniffer.captureSinglePacket()) {
        return 1;
    }

    return 0;
}
