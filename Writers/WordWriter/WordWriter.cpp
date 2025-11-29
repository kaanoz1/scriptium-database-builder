#include "WordWriter.h"

#include <algorithm>
#include <format>
#include <stdexcept>

#include "../../Utils/Logger/Logger.h"
#include "../RootWriter/RootWriter.h"

namespace scrptm {
    unsigned long long WordWriter::findLanguageIdByCode(const std::string &langCode) {
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

    WordWriter::WordWriter(nanodbc::connection &connection, unsigned long long verseId) : wordId(std::nullopt),
        connection(connection), verseId(verseId) {
        if (this->connection.connected() == false) {
            Logger::LogFatal("Connection is not established");
            throw std::runtime_error("Connection is not established");
        }
    }

    std::optional<unsigned long long> WordWriter::checkIfWordExist(const Word &word) {
        const std::string check_sql =
                "SELECT id FROM word WHERE verse_id = ? AND sequence_number = ?;";

        const unsigned long long verseId = this->verseId;
        const int wordNumber = static_cast<int>(word.getSequenceNumber());

        try {
            nanodbc::statement stmt(connection);
            nanodbc::prepare(stmt, check_sql);
            stmt.bind(0, &verseId);
            stmt.bind(1, &wordNumber);

            nanodbc::result results = stmt.execute();

            if (results.next()) {
                return results.get<unsigned long long>(0);
            }
            return std::nullopt;
        } catch (const nanodbc::database_error &e) {
            Logger::LogError(std::format("Error checking word existence: {}", e.what()));
            return std::nullopt;
        }
    }


    void WordWriter::matchRoots(unsigned long long wordId, const std::vector<unsigned long long> &rootIds) {


        if (rootIds.empty()) {
            Logger::LogInformation(std::format("No root IDs provided to match for Word ID: {}. Skipping matching.",
                                               wordId));
            return;
        }

        Logger::LogInformation(std::format("Starting to match {} roots for Word ID: {} in RootWord table.",
                                           rootIds.size(), wordId));

        const std::string insert_sql =
                "INSERT INTO RootWord (WordsId, RootsId) VALUES (?, ?);";


        nanodbc::statement stmt(connection);
        nanodbc::prepare(stmt, insert_sql);

        int matches_written_count = 0;

        for (const unsigned long long rootId: rootIds) {
            try {
                unsigned long long word_id_val = wordId;
                stmt.bind(0, &word_id_val);

                unsigned long long root_id_val = rootId;
                stmt.bind(1, &root_id_val);


                stmt.execute();
                matches_written_count++;
            } catch (const nanodbc::database_error &e) {
                if (std::string(e.what()).find("duplicate key") != std::string::npos) {
                    Logger::LogWarning(std::format("Match (Word ID: {}, Root ID: {}) already exists. Skipping.",
                                                   wordId, rootId));
                } else {

                    Logger::LogError(std::format(
                        "❌ Critical database error inserting RootWord (Word ID: {}, Root ID: {}): {}",
                        wordId, rootId, e.what()));
                    throw;
                }
            }
        }


        if (matches_written_count > 0) {
            Logger::LogSuccess(std::format("Successfully matched {} roots in RootWord table (Uncommitted).",
                                           matches_written_count));
        } else {
            Logger::LogWarning("No new RootWord records were written.");
        }
    }


    unsigned long long WordWriter::insertWord(const Word &word) {
        const std::string insert_sql =
                "INSERT INTO word (text, sequence_number, verse_id) "
                "OUTPUT inserted.id "
                "VALUES (?, ?, ?);";


        nanodbc::statement stmt(connection);
        nanodbc::prepare(stmt, insert_sql);

        const std::string text_val = word.getText();
        const int number_val = word.getSequenceNumber();
        const unsigned long long verse_id_val = this->verseId;

        stmt.bind(0, text_val.c_str());
        stmt.bind(1, &number_val);
        stmt.bind(2, &verse_id_val);

        nanodbc::result results = stmt.execute();

        if (results.next()) {
            unsigned long long new_id = results.get<long long>(0);
            Logger::LogInformation(
                std::format("Word base record inserted (Uncommitted). Temporary ID: {}", new_id));

            return new_id;
        }

        throw std::runtime_error(
            std::format("Failed to retrieve the new ID after word insertion.")
        );
    }


    void WordWriter::write(const Word &word) {
        Logger::LogInformation(std::format("Starting write operation for Word: {} (Number: {})",
                                           word.getText(), word.getSequenceNumber()));

        wordId = checkIfWordExist(word);

        unsigned long long targetWordId;

        if (wordId.has_value()) {
            targetWordId = wordId.value();
            Logger::LogInformation(std::format(
                "Word record already exists with ID: {}. Preparing to write meanings and transliterations.",
                targetWordId
            ));
        } else {
            Logger::LogInformation("Word record not found. New record will be inserted.");
            targetWordId = 0;
        }

        try {
            if (!wordId.has_value()) {
                targetWordId = insertWord(word);
                wordId = targetWordId;
                Logger::LogInformation(std::format(
                    "New Word base record inserted (Uncommitted). ID: {}",
                    targetWordId
                ));
            }


            std::vector<unsigned long long> rootIds = writeRoots(targetWordId, word.getRoots());

            matchRoots(wordId.value(), rootIds);

            Logger::LogInformation("All transactional inserts (Word and sub components) succeeded in memory.");
        } catch (const nanodbc::database_error &e) {
            Logger::LogError(std::format(
                "❌ FATAL DATABASE ERROR during Word transaction. All changes rolled back. Details: {}",
                e.what()
            ));
            throw;
        } catch (const std::runtime_error &e) {
            Logger::LogError(std::format(
                "❌ LOGIC ERROR during Word transaction. Details: {}",
                e.what()
            ));
            throw;
        }
    }

    std::vector<unsigned long long> WordWriter::writeRoots(unsigned long long targetWordId,
                                                           const std::vector<std::unique_ptr<Root> > &roots) {
        std::vector<unsigned long long> rootIds{};

        for (const auto &root: roots) {

            if (root == nullptr) continue;

            RootWriter root_writer{connection};

            unsigned long long rootId = root_writer.write(*root);

            rootIds.push_back(rootId);
        }

        return rootIds;
    }
} // scrptm
