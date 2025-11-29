#include "ScriptureWriter.h"

#include <format>

#include "../../Utils/Logger/Logger.h"
#include "../SectionWriter/SectionWriter.h"

namespace scrptm {
    ScriptureWriter::ScriptureWriter(nanodbc::connection &connection) : existingScriptureId(std::nullopt),
                                                                        connection(connection) {
        if (this->connection.connected() == false) {
            Logger::LogFatal("Connection is not established");
            throw std::runtime_error("Connection is not established");
        }
    }

    unsigned long long ScriptureWriter::findLanguageIdByCode(const std::string &langCode) {
        const std::string check_sql = "SELECT id FROM language WHERE lang_code = ?;";

        try {
            nanodbc::statement stmt(connection);
            nanodbc::prepare(stmt, check_sql);

            stmt.bind(0, langCode.c_str());

            if (nanodbc::result results = stmt.execute(); results.next()) {
                return results.get<unsigned long long>(0);
            }

            throw std::runtime_error(std::format("Language code not found. LangCode: {}", langCode));
        } catch (const nanodbc::database_error &e) {
            Logger::LogError(std::format("Error finding language ID for code '{}': {}", langCode, e.what()));
            throw std::runtime_error(std::format("Error. Err: {}", e.what()));
        }
    }


    void ScriptureWriter::writeMeanings(unsigned long long targetScriptureId,
                                        const std::vector<std::unique_ptr<ScriptureMeaning> > &scriptureMeanings) {
        if (scriptureMeanings.empty()) {
            Logger::LogInformation("No ScriptureMeanings found to write.");
            return;
        }

        Logger::LogInformation(std::format("Starting to write {} ScriptureMeanings for Scripture ID: {}",
                                           scriptureMeanings.size(), targetScriptureId));

        const std::string insert_sql =
                "INSERT INTO scripture_meaning (meaning, scripture_id, language_id) VALUES (?, ?, ?);";

        nanodbc::statement stmt(connection);
        nanodbc::prepare(stmt, insert_sql);

        int meanings_written_count = 0;

        for (const auto &meaning_ptr: scriptureMeanings) {
            const std::string meaning_text = meaning_ptr->getMeaning();
            const std::string lang_code = meaning_ptr->getLanguage().getLanguageCode();




            try {

                stmt.bind(0, meaning_text.c_str());

                unsigned long long scripture_id_val = targetScriptureId;
                stmt.bind(1, &scripture_id_val);

                unsigned long long language_id_val = lang_id;
                stmt.bind(2, &language_id_val);

                stmt.execute();
                meanings_written_count++;
            } catch (const nanodbc::database_error &e) {
                Logger::LogError(std::format("❌ Database error inserting meaning '{}' (Lang ID: {}): {}",
                                             meaning_text, lang_id, e.what()));
                throw;
            }
        }

        if (meanings_written_count > 0) {
            Logger::LogSuccess(std::format("Successfully wrote {} ScriptureMeaning records (Uncommitted).",
                                           meanings_written_count));
        } else {
            Logger::LogWarning("No ScriptureMeaning records were successfully written.");
        }
    }

    void ScriptureWriter::write(const Scripture &scripture) {
        Logger::LogInformation("Starting data integrity check and write operation.");

        existingScriptureId = checkIfScriptureExist();

        unsigned long long targetScriptureId;

        if (existingScriptureId.has_value()) {
            targetScriptureId = existingScriptureId.value();
            Logger::LogInformation(std::format(
                "Scripture record already exists with ID: {}. Preparing to write sections.",
                targetScriptureId
            ));
        } else {
            Logger::LogInformation("Scripture record not found. New record will be inserted.");
            targetScriptureId = 0;
        }

        try {
            nanodbc::transaction db_transaction(connection);


            if (!existingScriptureId.has_value()) {
                targetScriptureId = insertScripture(scripture);
                existingScriptureId = targetScriptureId;
                Logger::LogInformation(std::format(
                    "New Scripture base record inserted (Uncommitted). ID: {}",
                    targetScriptureId
                ));
            }

            writeMeanings(targetScriptureId, scripture.getMeanings());


            writeSections(targetScriptureId, scripture.getSections());

            Logger::LogInformation("All transactional inserts (Scripture and sub components) succeeded in memory.");


            std::cout << "\n=======================================================" << std::endl;
            std::cout << "  All database operations have been successfully verified (Uncommitted)." << std::endl;
            std::cout << "  Do you want to permanently commit these changes? (Y/n): ";

            std::string response;
            std::getline(std::cin, response);

            if (response == "Y" || response == "y") {
                db_transaction.commit();
                Logger::LogSuccess(std::format(
                    "✅ Transaction committed successfully. Target Scripture ID: {}",
                    targetScriptureId
                ));
            } else {
                db_transaction.rollback();
                Logger::LogWarning("Transaction explicitly rolled back. No data was saved.");
            }
        } catch (const nanodbc::database_error &e) {
            Logger::LogError(std::format(
                "❌ FATAL DATABASE ERROR during transaction. All changes rolled back. Details: {}",
                e.what()
            ));
            throw;
        }
    }

    std::optional<unsigned long long> ScriptureWriter::checkIfScriptureExist() {
        const std::string check_sql =
                "SELECT id FROM scripture WHERE code = ?;";

        const std::string scriptureCode = "t";

        try {
            nanodbc::statement stmt(connection);
            nanodbc::prepare(stmt, check_sql);
            stmt.bind(0, scriptureCode.c_str());
            nanodbc::result results = stmt.execute();

            if (results.next()) {
                return results.get<unsigned long long>(0);
            }
            return std::nullopt;
        } catch (const nanodbc::database_error &e) {
            Logger::LogError(std::format("Error checking existence: {}", e.what()));
            return std::nullopt;
        }
    }


    unsigned long long ScriptureWriter::insertScripture(const Scripture &scripture) {
        const std::string insert_sql =
                "INSERT INTO scripture (name, number, code) "
                "OUTPUT inserted.id "
                "VALUES (?, ?, ?);";


        nanodbc::statement stmt(connection);
        nanodbc::prepare(stmt, insert_sql);

        const std::string name_val = scripture.getName();
        const int number_val = scripture.getNumber();
        const std::string code_val = std::to_string(scripture.getCode());

        stmt.bind(0, name_val.c_str());

        stmt.bind(1, &number_val);

        stmt.bind(2, code_val.substr(0, 1).c_str());

        nanodbc::result results = stmt.execute();


        if (results.next()) {
            unsigned long long new_id = results.get<long long>(0);
            Logger::LogInformation(
                std::format("Scripture base record inserted (Uncommitted). Temporary ID: {}", new_id));

            return new_id;
        }

        throw std::runtime_error(
            std::format("A Faild to retrieve the new IDENTITY ID after insertion.")
        );
    }

    void ScriptureWriter::writeSections(unsigned long long scriptureId,
                                        const std::vector<std::unique_ptr<Section> > &sections) {

        for (const auto& section : sections) {
            SectionWriter section_writer{this->connection, scriptureId};

            section_writer.write(*section);

        }


    }
} // scrptm
