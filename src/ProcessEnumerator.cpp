#include "ProcessEnumerator.h"
#include <dirent.h>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>

// Lee /proc y devuelve lista de (pid, name). Solo lectura pasiva: no interactúa con procesos.
std::vector<std::pair<int,std::string>> listProcesses() {
    std::vector<std::pair<int,std::string>> out;
    DIR* d = opendir("/proc");
    if (!d) return out;
    struct dirent* entry;
    while ((entry = readdir(d)) != nullptr) {
        const char* name = entry->d_name;
        bool digits = true;
        for (int i = 0; name[i] != '\0'; ++i)
            if (!std::isdigit((unsigned char)name[i])) { digits = false; break; }
        if (!digits) continue;
        std::string path = std::string("/proc/") + name + "/comm";
        std::ifstream ifs(path);
        if (ifs) {
            std::string procname;
            std::getline(ifs, procname);
            out.emplace_back(std::atoi(name), procname);
        }
    }
    closedir(d);
    return out;
}
