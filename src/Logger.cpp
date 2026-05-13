#include "Logger.h"
#include <iostream>
#include <chrono>
#include <ctime>

Logger::Logger(const std::string& file) {
    if (!file.empty()) ofs_.open(file, std::ios::app);
}

Logger::~Logger() {
    if (ofs_.is_open()) ofs_.close();
}

void Logger::info(const std::string& msg) {
    std::lock_guard<std::mutex> lk(mtx_);
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    if (ofs_.is_open()) ofs_ << "[INFO] " << std::ctime(&now) << " " << msg << std::endl;
    std::cout << "[INFO] " << msg << std::endl;
}

void Logger::error(const std::string& msg) {
    std::lock_guard<std::mutex> lk(mtx_);
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    if (ofs_.is_open()) ofs_ << "[ERROR] " << std::ctime(&now) << " " << msg << std::endl;
    std::cerr << "[ERROR] " << msg << std::endl;
}
