#include "HashGenerator.h"
#include "FileReader.h"
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>

// Hash SHA256 usando OpenSSL. No almacena claves ni información sensible.
std::string hashFromBytes(const std::vector<unsigned char>& data) {
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    if (!data.empty()) SHA256_Update(&ctx, data.data(), data.size());
    SHA256_Final(digest, &ctx);

    std::ostringstream oss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)digest[i];
    return oss.str();
}

std::string hashFromFile(const std::string& path) {
    auto data = readFile(path);
    if (data.empty()) return {};
    return hashFromBytes(data);
}