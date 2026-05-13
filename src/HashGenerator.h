#pragma once
#include <string>
#include <vector>

// Calcula SHA256 de datos binarios y devuelve hex en minúsculas.
std::string hashFromBytes(const std::vector<unsigned char>& data);
std::string hashFromFile(const std::string& path);