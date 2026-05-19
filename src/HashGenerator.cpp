#include "HashGenerator.h"
#include "FileReader.h"
#include <openssl/evp.h>
#include <openssl/err.h>
#include <sstream>
#include <iomanip>
#include <cstring>

// Usar EVP (versión compatible con OpenSSL 3.0). Evita warnings de deprecación.
std::string hashFromBytes(const std::vector<unsigned char>& data) {
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int digest_len = 0;

    EVP_MD_CTX* mdctx = EVP_MD_CTX_new();
    if (!mdctx) return {};

    if (EVP_DigestInit_ex(mdctx, EVP_sha256(), nullptr) != 1) {
        EVP_MD_CTX_free(mdctx);
        return {};
    }
    if (!data.empty() && EVP_DigestUpdate(mdctx, data.data(), data.size()) != 1) {
        EVP_MD_CTX_free(mdctx);
        return {};
    }
    if (EVP_DigestFinal_ex(mdctx, digest, &digest_len) != 1) {
        EVP_MD_CTX_free(mdctx);
        return {};
    }
    EVP_MD_CTX_free(mdctx);

    std::ostringstream oss;
    for (unsigned int i = 0; i < digest_len; ++i)
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)digest[i];
    return oss.str();
}

std::string hashFromFile(const std::string& path) {
    auto data = readFile(path);
    if (data.empty()) return {};
    return hashFromBytes(data);
}