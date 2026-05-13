#pragma once
#include <string>
#include <vector>

// Lee archivo binario y devuelve bytes; devuelve vector vacío si falla.
std::vector<unsigned char> readFile(const std::string& path);