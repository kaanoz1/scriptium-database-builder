//
// Created by prag on 11/17/25.
//

#include "Logger.h"
#include <ctime>
#include <sstream>
#include <iomanip>

namespace scrptm {
    std::mutex Logger::s_mutex;

    std::string_view Logger::getLevelAbbreviation(LogLevel level) {
        switch (level) {
            case LogLevel::Debug: return "DEBUG";
            case LogLevel::Information: return "INFO";
            case LogLevel::Warning: return "WARN";
            case LogLevel::Error: return "ERROR";
            case LogLevel::Fatal: return "FATAL";
            default: return "UNKNOWN";
        }
    }

    std::string_view Logger::getLevelColorCode(LogLevel level) {
        switch (level) {
            case LogLevel::Debug: return "\033[90m";
            case LogLevel::Information: return "\033[34m";
            case LogLevel::Warning: return "\033[33m";
            case LogLevel::Error: return "\033[31m";
            case LogLevel::Fatal: return "\033[41m\033[97m";
            default: return "\033[0m";
        }
    }

    void Logger::Log(LogLevel level, std::string_view message, std::ostream &stream) {
        // 1. Thread-Safe Kilitleme
        std::lock_guard<std::mutex> lock(s_mutex);

        // 2. 🕒 Zaman Damgası Oluşturma
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);

        // C++17 sonrası std::put_time ile uyumlu olması için yerel zamana dönüştürme
        std::tm timeinfo = *std::localtime(&now_c);

        std::stringstream ss;
        // Zaman formatı: YYYY-MM-DD HH:MM:SS
        ss << std::put_time(&timeinfo, "%Y-%m-%d %H:%M:%S");

        // 3. Log Çıktısını Hazırlama

        // Çıktı formatı: [ZAMAN] [RENKLİ SEVİYE] MESAJ
        stream << "[" << ss.str() << "] "
                << getLevelColorCode(level) // Renk kodu
                << "[" << getLevelAbbreviation(level) << "]"
                << "\033[0m " // Rengi sıfırla
                << message << "\n";

        stream.flush();
    }
} // scrptm
