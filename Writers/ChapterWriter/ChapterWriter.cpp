#include "ChapterWriter.h"

#include <format>
#include <stdexcept>

#include "../../Utils/Logger/Logger.h"
#include "../VerseWriter/VerseWriter.h"

namespace scrptm {

    unsigned long long ChapterWriter::findLanguageIdByCode(const std::string &langCode) {
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

    ChapterWriter::ChapterWriter(nanodbc::connection &connection, unsigned long long sectionId) : chapterId(std::nullopt),
                                                                   connection(connection), sectionId(sectionId) {
        if (this->connection.connected() == false) {
            Logger::LogFatal("Connection is not established");
            throw std::runtime_error("Connection is not established");
        }
    }

    std::optional<unsigned long long> ChapterWriter::checkIfChapterExist(const Chapter& chapter) {
        const std::string check_sql =
                "SELECT id FROM chapter WHERE section_id = ? AND number = ?;";

        const unsigned long long sectionId = this->sectionId;
        const int chapterNumber = chapter.getNumber();

        try {
            nanodbc::statement stmt(connection);
            nanodbc::prepare(stmt, check_sql);
            stmt.bind(0, &sectionId);
            stmt.bind(1, &chapterNumber);

            nanodbc::result results = stmt.execute();

            if (results.next()) {
                return results.get<unsigned long long>(0);
            }
            return std::nullopt;
        } catch (const nanodbc::database_error &e) {
            Logger::LogError(std::format("Error checking chapter existence: {}", e.what()));
            return std::nullopt;
        }
    }


    unsigned long long ChapterWriter::insertChapter(const Chapter &chapter) {
        const std::string insert_sql =
                "INSERT INTO chapter (name, number, section_id) "
                "OUTPUT inserted.id "
                "VALUES (?, ?, ?);";


        nanodbc::statement stmt(connection);
        nanodbc::prepare(stmt, insert_sql);

        const std::string name_val = chapter.getName();
        const int number_val = chapter.getNumber();
        const unsigned long long section_id_val = this->sectionId;

        stmt.bind(0, name_val.c_str());
        stmt.bind(1, &number_val);
        stmt.bind(2, &section_id_val);

        nanodbc::result results = stmt.execute();

        if (results.next()) {
            unsigned long long new_id = results.get<long long>(0);
            Logger::LogInformation(
                std::format("Chapter base record inserted (Uncommitted). Temporary ID: {}", new_id));

            return new_id;
        }

        throw std::runtime_error(
            std::format("Failed to retrieve the new ID after chapter insertion.")
        );
    }

    void ChapterWriter::writeMeanings(unsigned long long targetChapterId,
                                      const std::vector<std::unique_ptr<ChapterMeaning> > &chapterMeanings) {
        if (chapterMeanings.empty()) {
            Logger::LogInformation(std::format("No ChapterMeanings found to write for Chapter ID: {}", targetChapterId));
            return;
        }

        Logger::LogInformation(std::format("Starting to write {} ChapterMeanings for Chapter ID: {}",
                                           chapterMeanings.size(), targetChapterId));

        const std::string insert_sql =
                "INSERT INTO chapter_meaning (meaning, chapter_id, language_id) VALUES (?, ?, ?);";

        nanodbc::statement stmt(connection);
        nanodbc::prepare(stmt, insert_sql);

        int meanings_written_count = 0;

        for (const auto &meaning_ptr: chapterMeanings) {
            const std::string meaning_text = meaning_ptr->getMeaning();
            const std::string lang_code = meaning_ptr->getLanguage().getLanguageCode();

            unsigned long long lang_id = findLanguageIdByCode(lang_code);

            try {
                stmt.bind(0, meaning_text.c_str());

                unsigned long long chapter_id_val = targetChapterId;
                stmt.bind(1, &chapter_id_val);

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
            Logger::LogSuccess(std::format("Successfully wrote {} ChapterMeaning records (Uncommitted).",
                                           meanings_written_count));
        } else {
            Logger::LogWarning("No ChapterMeaning records were successfully written.");
        }
    }


    void ChapterWriter::write(const Chapter &chapter) {
        Logger::LogInformation(std::format("Starting write operation for Chapter: {} (Number: {})",
                                           chapter.getName(), chapter.getNumber()));

        chapterId = checkIfChapterExist(chapter);

        unsigned long long targetChapterId;

        if (chapterId.has_value()) {
            targetChapterId = chapterId.value();
            Logger::LogInformation(std::format(
                "Chapter record already exists with ID: {}. Preparing to write meanings and verses.",
                targetChapterId
            ));
        } else {
            Logger::LogInformation("Chapter record not found. New record will be inserted.");
            targetChapterId = 0;
        }

        try {
            nanodbc::transaction db_transaction(connection);

            if (!chapterId.has_value()) {
                targetChapterId = insertChapter(chapter);
                chapterId = targetChapterId;
                Logger::LogInformation(std::format(
                    "New Chapter base record inserted (Uncommitted). ID: {}",
                    targetChapterId
                ));
            }

            writeMeanings(targetChapterId, chapter.getMeanings());

            writeVerses(targetChapterId, chapter.getVerses());

            Logger::LogInformation("All transactional inserts (Chapter and sub components) succeeded in memory.");


        } catch (const nanodbc::database_error &e) {
            Logger::LogError(std::format(
                "❌ FATAL DATABASE ERROR during Chapter transaction. All changes rolled back. Details: {}",
                e.what()
            ));
            throw;
        } catch (const std::runtime_error &e) {
             Logger::LogError(std::format(
                "❌ LOGIC ERROR during Chapter transaction. Details: {}",
                e.what()
            ));
            throw;
        }
    }

    void ChapterWriter::writeVerses(unsigned long long chapterId,
                                        const std::vector<std::unique_ptr<Verse>> &verses) {
        Logger::LogInformation(std::format("Verse write initialized for Chapter ID: {}", chapterId));


        for (const auto& verse: verses) {
            VerseWriter verse_writer{connection, chapterId};

            verse_writer.write(*verse);
        }



    }

} // scrptm