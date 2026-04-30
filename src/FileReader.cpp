#include "FileReader.h"
#include <fstream>
#include <vector>
#include <string>

std::vector<unsigned char> readFile(const std::string& path) {
    std::ifstream file(path, std::ios::binary);

    if (!file) {
        return {};
    }

    return std::vector<unsigned char>(
        std::istreambuf_iterator<char>(file),
        std::istreambuf_iterator<char>()
    );
}