#pragma once
#include <string>

// Captura N paquetes en la interfaz dada (no promiscuo por defecto).
// Retorna 0 si ok, !=0 si error.
int sniffInterface(const std::string& interface, int packet_count = 10);
