#include "SectionWriter.h"

#include <format>
#include <iostream>

#include "../../Utils/Logger/Logger.h"
#include "../ChapterWriter/ChapterWriter.h"

namespace scrptm {
    unsigned long long SectionWriter::findLanguageIdByCode(const std::string &langCode) {
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

    SectionWriter::SectionWriter(nanodbc::connection &connection,
                                 unsigned long long scriptureId) : sectionId(std::nullopt),
                                                                   connection(connection), scriptureId(scriptureId) {
        if (this->connection.connected() == false) {
            Logger::LogFatal("Connection is not established");
            throw std::runtime_error("Connection is not established");
        }
    }

    std::optional<unsigned long long> SectionWriter::checkIfSectionExist(const Section &section) {
        const std::string check_sql =
                "SELECT id FROM section WHERE scripture_id = ? AND number = ?;";

        const int sectionNumber = section.getNumber();


        try {
            nanodbc::statement stmt(connection);
            nanodbc::prepare(stmt, check_sql);
            stmt.bind(0, &this->scriptureId);
            stmt.bind(1, &sectionNumber);

            nanodbc::result results = stmt.execute();

            if (results.next()) {
                return results.get<unsigned long long>(0);
            }
            return std::nullopt;
        } catch (const nanodbc::database_error &e) {
            Logger::LogError(std::format("Error checking section existence: {}", e.what()));
            return std::nullopt;
        }
    }


    unsigned long long SectionWriter::insertSection(const Section &section) {
        const std::string insert_sql =
                "INSERT INTO section (name, number, scripture_id) "
                "OUTPUT inserted.id "
                "VALUES (?, ?, ?);";


        nanodbc::statement stmt(connection);
        nanodbc::prepare(stmt, insert_sql);

        const std::string name_val = section.getName();
        const int number_val = section.getNumber();
        const unsigned long long scripture_id_val = this->scriptureId;

        stmt.bind(0, name_val.c_str());
        stmt.bind(1, &number_val);
        stmt.bind(2, &scripture_id_val);

        nanodbc::result results = stmt.execute();

        if (results.next()) {
            unsigned long long new_id = results.get<long long>(0);
            Logger::LogInformation(
                std::format("Section ({}, {}) base record inserted (Uncommitted). Temporary ID: {}", section.getName(),
                            section.getMeanings().at(0)->getMeaning(), new_id));

            return new_id;
        }

        throw std::runtime_error(
            std::format("Failed to retrieve the new ID after section insertion.")
        );
    }

    void SectionWriter::writeMeanings(unsigned long long targetSectionId,
                                      const std::vector<std::unique_ptr<SectionMeaning> > &sectionMeanings) {
        if (sectionMeanings.empty()) {
            Logger::LogInformation(std::format("No SectionMeanings found to write for section ID: {}", targetSectionId));
            return;
        }

        Logger::LogInformation(std::format("Starting to write {} SectionMeanings for Section ID: {}",
                                           sectionMeanings.size(), targetSectionId));

        const std::string insert_sql =
                "INSERT INTO section_meaning (meaning, section_id, language_id) VALUES (?, ?, ?);";

        nanodbc::statement stmt(connection);
        nanodbc::prepare(stmt, insert_sql);

        int meanings_written_count = 0;

        for (const auto &meaning_ptr: sectionMeanings) {
            const std::string meaning_text = meaning_ptr->getMeaning();
            const std::string lang_code = meaning_ptr->getLanguage().getLanguageCode();

            unsigned long long lang_id = findLanguageIdByCode(lang_code);

            try {
                stmt.bind(0, meaning_text.c_str());

                unsigned long long section_id_val = targetSectionId;
                stmt.bind(1, &section_id_val);

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
            Logger::LogSuccess(std::format("Successfully wrote {} SectionMeaning records (Uncommitted).",
                                           meanings_written_count));
        } else {
            Logger::LogWarning("No SectionMeaning records were successfully written.");
        }
    }


    void SectionWriter::write(const Section &section) {
        Logger::LogInformation(std::format("Starting write operation for Section: {} (Number: {})",
                                           section.getName(), section.getNumber()));

        sectionId = checkIfSectionExist(section);

        unsigned long long targetSectionId;

        if (sectionId.has_value()) {
            targetSectionId = sectionId.value();
            Logger::LogInformation(std::format(
                "Section record already exists with ID: {}. Preparing to write meanings and chapters.",
                targetSectionId
            ));
        } else {
            Logger::LogInformation("Section record not found. New record will be inserted.");
            targetSectionId = 0;
        }

        try {
            nanodbc::transaction db_transaction(connection);

            if (!sectionId.has_value()) {
                targetSectionId = insertSection(section);
                sectionId = targetSectionId;
                Logger::LogInformation(std::format(
                    "New Section base record inserted (Uncommitted). ID: {}",
                    targetSectionId
                ));
            }

            writeMeanings(targetSectionId, section.getMeanings());

            writeChapters(targetSectionId, section.getChapters());

            Logger::LogInformation("All transactional inserts (Section and sub components) succeeded in memory.");


        } catch (const nanodbc::database_error &e) {
            Logger::LogError(std::format(
                "❌ FATAL DATABASE ERROR during Section transaction. All changes rolled back. Details: {}",
                e.what()
            ));
            throw;
        } catch (const std::runtime_error &e) {
            Logger::LogError(std::format(
                "❌ LOGIC ERROR during Section transaction. Details: {}",
                e.what()
            ));
            throw;
        }
    }

    void SectionWriter::writeChapters(unsigned long long insertedSectionId,
                                      const std::vector<std::unique_ptr<Chapter> > &chapters) {

    for (const auto& chapter: chapters) {
        ChapterWriter writer{connection, sectionId.value()};

        writer.write(*chapter);
    }

    }
} // scrptm
