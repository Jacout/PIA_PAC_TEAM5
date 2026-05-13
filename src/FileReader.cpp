#include "FileReader.h"
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

std::vector<unsigned char> readFile(const std::string& path) {
    std::ifstream file(path, std::ios::binary);
    if (!file) {
        return {};
    }

    // Obtener tamaño para reservar capacidad
    file.seekg(0, std::ios::end);
    std::streampos size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<unsigned char> data;
    if (size > 0) data.reserve(static_cast<size_t>(size));

    std::istreambuf_iterator<char> it(file);
    std::istreambuf_iterator<char> end;
    std::transform(it, end, std::back_inserter(data),
                   [](char c) { return static_cast<unsigned char>(c); });

    return data;
}