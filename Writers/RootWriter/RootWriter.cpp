#include "RootWriter.h"

#include <format>
#include <stdexcept>

#include "../../Utils/Logger/Logger.h"

namespace scrptm {


    RootWriter::RootWriter(nanodbc::connection &connection) : rootId(std::nullopt),
                                                             connection(connection) {
        if (this->connection.connected() == false) {
            Logger::LogFatal("Connection is not established");
            throw std::runtime_error("Connection is not established");
        }
    }

    std::optional<unsigned long long> RootWriter::checkIfRootExist(const Root& root) {
        const std::string check_sql =
                "SELECT id FROM root WHERE latin = ?;";

        const std::string rootLatin = root.getLatin();

        try {
            nanodbc::statement stmt(connection);
            nanodbc::prepare(stmt, check_sql);
            stmt.bind(0, rootLatin.c_str());

            nanodbc::result results = stmt.execute();

            if (results.next()) {
                return results.get<unsigned long long>(0);
            }
            return std::nullopt;
        } catch (const nanodbc::database_error &e) {
            Logger::LogError(std::format("Error checking root existence: {}", e.what()));
            return std::nullopt;
        }
    }


    unsigned long long RootWriter::insertRoot(const Root &root) {
        const std::string insert_sql =
                "INSERT INTO root (latin, own, scripture_id) "
                "OUTPUT inserted.id "
                "VALUES (?, ?, 133);";


        nanodbc::statement stmt(connection);
        nanodbc::prepare(stmt, insert_sql);

        const std::string latin = root.getLatin();
        const std::string own = root.getOwn();

        stmt.bind(0, latin.c_str());
        stmt.bind(1, own.c_str());

        nanodbc::result results = stmt.execute();

        if (results.next()) {
            unsigned long long new_id = results.get<long long>(0);
            Logger::LogInformation(
                std::format("Root base record inserted (Uncommitted). Temporary ID: {}", new_id));

            return new_id;
        }

        throw std::runtime_error(
            std::format("Failed to retrieve the new ID after root insertion.")
        );
    }


    unsigned long long RootWriter::write(const Root &root) {
        Logger::LogInformation(std::format("Starting write operation for Root: {}",
                                           root.getOwn()));

        rootId = checkIfRootExist(root);

        unsigned long long targetRootId;

        if (rootId.has_value()) {
            targetRootId = rootId.value();
            Logger::LogInformation(std::format(
                "Root record already exists with ID: {}. Preparing to write meanings.",
                targetRootId
            ));
        } else {
            Logger::LogInformation("Root record not found. New record will be inserted.");
            targetRootId = 0;
        }

        try {
            if (!rootId.has_value()) {
                targetRootId = insertRoot(root);
                rootId = targetRootId;
                Logger::LogInformation(std::format(
                    "New Root base record inserted (Uncommitted). ID: {}",
                    targetRootId
                ));
            }


            Logger::LogInformation("All transactional inserts (Root and meanings) succeeded in memory.");

            return targetRootId;

        } catch (const nanodbc::database_error &e) {
            Logger::LogError(std::format(
                "❌ FATAL DATABASE ERROR during Root transaction. All changes rolled back. Details: {}",
                e.what()
            ));
            throw;
        } catch (const std::runtime_error &e) {
             Logger::LogError(std::format(
                "❌ LOGIC ERROR during Root transaction. Details: {}",
                e.what()
            ));
            throw;
        }
    }

} // scrptm