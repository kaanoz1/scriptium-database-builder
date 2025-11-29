#include "DatabasePool.h"

#include <format>
#include <iostream>
#include <ostream>

#include "../ScriptureWriter/ScriptureWriter.h"

namespace scrptm {
    DatabasePool::DatabasePool() {
        connectionString = getenv("SCRIPTIUM_DB_CONNECTION_STRING");
    }

    void DatabasePool::printConnectionString() const noexcept {
        const char *connStr = this->getConnectionString();

        if (connStr == nullptr) {
            std::cerr << std::format("Connection string is NULL") << std::endl;
            return;
        }

        std::cout << std::format("Connection string is {}", connStr) << std::endl;
    }

    DatabasePool::~DatabasePool() {
        this->connection_.disconnect();
    }


    const char *DatabasePool::getConnectionString() const noexcept {
        return this->connectionString;
    }

    bool DatabasePool::isConnected() const {
        return connection_.connected();
    }

    nanodbc::connection &DatabasePool::getConnection() noexcept {
        return connection_;
    }

    bool DatabasePool::connect() {
        const char *conn_str_c = this->getConnectionString();

        if (conn_str_c == nullptr) {
            Logger::LogFatal(
                "Connection failed: Connection string is  not found (NULL)."
            );
            return false;
        }

        std::string connection_string(conn_str_c);

        Logger::LogInformation(std::format("Attempting to connect using connection string: {}", connection_string));

        try {
            this->connection_.connect(connection_string);

            if (this->isConnected()) {
                Logger::LogSuccess("Database connection successful.");

                if (nanodbc::result results = nanodbc::execute(this->getConnection(), "SELECT DB_NAME()"); results.
                    next())
                    Logger::LogDebug(std::format("Currently connected to database: {}", results.get<std::string>(0)));

                return true;
            }


            Logger::LogError("Connection established, but nanodbc::connected() returned false.");
            return false;
        } catch (const nanodbc::database_error &e) {
            Logger::LogError(std::format(
                "DATABASE ERROR: Connection to SQL Server failed. Error details: {}",
                e.what()
            ));
            Logger::LogWarning(
                "HINT: Please check the 'Driver' name in the connection string and ensure the ODBC driver is installed.");
            return false;
        } catch (const std::exception &e) {
            Logger::LogError(std::format("❌ Unknown exception caught during connection: {}", e.what()));
            return false;
        }
    }

    void DatabasePool::writeScripture(const Scripture &scripture) {
        ScriptureWriter scripture_writer{this->getConnection()};


        scripture_writer.write(scripture);

        Logger::LogSuccess(std::format("Scripture ({}, {}) has successfully inserted.", scripture.getName(),
                                       scripture.getMeanings().at(0)->getMeaning()));
    }
} // scrptm
