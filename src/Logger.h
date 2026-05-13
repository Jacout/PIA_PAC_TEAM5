#pragma once
#include <string>
#include <mutex>
#include <fstream>

class Logger {
public:
    Logger(const std::string& file = "");
    ~Logger();
    void info(const std::string& msg);
    void error(const std::string& msg);
private:
    std::mutex mtx_;
    std::ofstream ofs_;
};
