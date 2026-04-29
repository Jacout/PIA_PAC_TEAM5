#ifndef SNIFFER_H
#define SNIFFER_H

#include <string>

class Sniffer {
public:
    // Constructor que recibe la interfaz de red (ej. eth0, wlp3s0, lo)
    Sniffer(const std::string& interfaceName);
    
    // Método para iniciar la captura de 1 paquete de prueba
    bool captureSinglePacket();

private:
    std::string interface_name;
};

#endif // SNIFFER_H
