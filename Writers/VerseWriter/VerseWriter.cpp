#include "VerseWriter.h"

#include <format>
#include <stdexcept>

#include "../../Utils/Logger/Logger.h"
#include "../WordWriter/WordWriter.h"

namespace scrptm {

    VerseWriter::VerseWriter(nanodbc::connection &connection, unsigned long long chapterId) : verseId(std::nullopt),
                                                                   connection(connection), chapterId(chapterId) {
        if (this->connection.connected() == false) {
            Logger::LogFatal("Connection is not established");
            throw std::runtime_error("Connection is not established");
        }
    }

    std::optional<unsigned long long> VerseWriter::checkIfVerseExist(const Verse& verse) {
        const std::string check_sql =
                "SELECT id FROM verse WHERE chapter_id = ? AND number = ?;";

        const unsigned long long chapterId = this->chapterId;
        const int verseNumber = verse.getNumber();

        try {
            nanodbc::statement stmt(connection);
            nanodbc::prepare(stmt, check_sql);
            stmt.bind(0, &chapterId);
            stmt.bind(1, &verseNumber);

            nanodbc::result results = stmt.execute();

            if (results.next()) {
                return results.get<unsigned long long>(0);
            }
            return std::nullopt;
        } catch (const nanodbc::database_error &e) {
            Logger::LogError(std::format("Error checking verse existence: {}", e.what()));
            return std::nullopt;
        }
    }


    unsigned long long VerseWriter::insertVerse(const Verse &verse) {
        const std::string insert_sql =
                "INSERT INTO verse (number, text, text_simplified, text_without_vowel, chapter_id) "
                "OUTPUT inserted.id "
                "VALUES (?, ?, ?, ?, ?);";


        nanodbc::statement stmt(connection);
        nanodbc::prepare(stmt, insert_sql);

        const int number_val = verse.getNumber();
        const std::string text = verse.getText();
        const std::string textNoVowel = verse.getText();
        const std::string textSimplified = verse.getText();

        const unsigned long long chapter_id_val = this->chapterId;

        stmt.bind(0, &number_val);
        stmt.bind(1, text.c_str());
        stmt.bind(2, textSimplified.c_str());
        stmt.bind(3, textNoVowel.c_str());
        stmt.bind(4, &chapter_id_val);

        nanodbc::result results = stmt.execute();

        if (results.next()) {
            unsigned long long new_id = results.get<long long>(0);
            Logger::LogInformation(
                std::format("Verse base record inserted (Uncommitted). Temporary ID: {}", new_id));

            return new_id;
        }

        throw std::runtime_error(
            std::format("Failed to retrieve the new ID after verse insertion.")
        );
    }

    void VerseWriter::write(const Verse &verse) {
        Logger::LogInformation(std::format("Starting write operation for Verse number: {}",
                                           verse.getNumber()));

        verseId = checkIfVerseExist(verse);

        unsigned long long targetVerseId;

        if (verseId.has_value()) {
            targetVerseId = verseId.value();
            verseId = targetVerseId;
            Logger::LogInformation(std::format(
                "Verse record already exists with ID: {}. Preparing to write words.",
                targetVerseId
            ));
        } else {
            Logger::LogInformation("Verse record not found. New record will be inserted.");
            targetVerseId = 0;
        }

        try {
            if (!verseId.has_value()) {
                targetVerseId = insertVerse(verse);
                verseId = targetVerseId;
                Logger::LogInformation(std::format(
                    "New Verse base record inserted (Uncommitted). ID: {}",
                    targetVerseId
                ));
            }

            writeWords(targetVerseId, verse.getWords());

            Logger::LogInformation("All transactional inserts (Verse and words) succeeded in memory.");


        } catch (const nanodbc::database_error &e) {
            Logger::LogError(std::format(
                "❌ FATAL DATABASE ERROR during Verse transaction. All changes rolled back. Details: {}",
                e.what()
            ));
            throw;
        } catch (const std::runtime_error &e) {
             Logger::LogError(std::format(
                "❌ LOGIC ERROR during Verse transaction. Details: {}",
                e.what()
            ));
            throw;
        }
    }

    void VerseWriter::writeWords(unsigned long long verseId,
                                        const std::vector<std::unique_ptr<Word>> &words) {
        Logger::LogInformation(std::format("Word write initialized for Verse ID: {}", verseId));


        for (const auto& word : words) {
            WordWriter writer{connection, verseId};
            writer.write(*word);
        }
    }

} // scrptm