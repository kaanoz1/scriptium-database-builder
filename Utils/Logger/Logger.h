
#ifndef SCRIPTIUM_DATABASE_BUILDER_LOGGER_H
#define SCRIPTIUM_DATABASE_BUILDER_LOGGER_H

#include <iostream>
#include <mutex>

namespace scrptm {

    class Logger {
    public:
        enum class LogLevel {
            Debug,
            Information,
            Warning,
            Error,
            Fatal
        };

    private:
        static std::mutex s_mutex;

        static std::string_view getLevelAbbreviation(LogLevel level);

        static std::string_view getLevelColorCode(LogLevel level);

        static void Log(LogLevel level, std::string_view message, std::ostream &stream);

    public:
        static void LogDebug(std::string_view message) {
            Log(LogLevel::Debug, message, std::cout);
        }

        static void LogInformation(std::string_view message) {
            Log(LogLevel::Information, message, std::cout);
        }

        static void LogWarning(std::string_view message) {
            Log(LogLevel::Warning, message, std::cout);
        }

        static void LogError(std::string_view message) {
            Log(LogLevel::Error, message, std::cerr);
        }

        static void LogFatal(std::string_view message) {
            Log(LogLevel::Fatal, message, std::cerr);
        }

        Logger() = delete;

        Logger(const Logger &) = delete;

        Logger &operator=(const Logger &) = delete;
    };
}

#endif //SCRIPTIUM_DATABASE_BUILDER_LOGGER_H
