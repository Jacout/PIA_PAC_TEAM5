#include "sniffer.h"
#include <pcap.h>
#include <iostream>

Sniffer::Sniffer(const std::string& interfaceName) : interface_name(interfaceName) {}

bool Sniffer::captureSinglePacket() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Abrir el dispositivo de red para captura en modo promiscuo
    // Argumentos: Interfaz, tamaño del buffer, modo promiscuo (1), timeout, buffer de errores
    handle = pcap_open_live(interface_name.c_str(), BUFSIZ, 1, 1000, errbuf);
    
    if (handle == nullptr) {
        std::cerr << "Error al abrir el dispositivo " << interface_name << ": " << errbuf << std::endl;
        return false;
    }

    std::cout << "[*] Escuchando en la interfaz: " << interface_name << std::endl;
    std::cout << "[*] Esperando el primer paquete..." << std::endl;

    struct pcap_pkthdr header;
    const u_char *packet;

    // Capturar exactamente un paquete
    packet = pcap_next(handle, &header);
    
    if (packet != nullptr) {
        std::cout << "\n[+] ¡Paquete capturado con éxito!" << std::endl;
        std::cout << "    -> Longitud total: " << header.len << " bytes." << std::endl;
        std::cout << "    -> Longitud capturada: " << header.caplen << " bytes." << std::endl;
    } else {
        std::cerr << "[-] No se capturó ningún paquete (timeout o error)." << std::endl;
    }

    // Cerrar el manejador
    pcap_close(handle);
    return true;
}
