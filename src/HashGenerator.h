#ifndef HASHGENERATOR_H
#define HASHGENERATOR_H

#include <vector>
#include <string>

std::string generateSHA256(const std::vector<unsigned char>& data);

#endif