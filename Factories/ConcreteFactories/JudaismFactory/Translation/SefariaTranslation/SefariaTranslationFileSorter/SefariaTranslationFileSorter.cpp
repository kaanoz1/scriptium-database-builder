#include "SefariaTranslationFileSorter.h"

#include <format>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include "../../../../../../Utils/Logger/Logger.h"

namespace scrptm {
    const std::vector<std::string> SefariaTranslationFileSorter::meanings =
    {
        "Genesis",
        "Exodus",
        "Leviticus",
        "Numbers",
        "Deuteronomy",
        "Joshua",
        "Judges",
        "Ruth",
        "I Samuel",
        "II Samuel",
        "I Kings",
        "II Kings",
        "I Chronicles",
        "II Chronicles",
        "Ezra",
        "Nehemiah",
        "Esther",
        "Job",
        "Psalms",
        "Proverbs",
        "Ecclesiastes",
        "Song of Songs",
        "Isaiah",
        "Jeremiah",
        "Lamentations",
        "Ezekiel",
        "Daniel",
        "Hosea",
        "Joel",
        "Amos",
        "Obadiah",
        "Jonah",
        "Micah",
        "Nahum",
        "Habakkuk",
        "Zephaniah",
        "Haggai",
        "Zechariah",
        "Malachi"
    };


    std::vector<std::optional<SefariaTranslationFile> >
    SefariaTranslationFileSorter::sort(std::vector<std::optional<SefariaTranslationFile> > &&files) {
        const size_t requiredSize = meanings.size();
        if (files.size() != requiredSize) {
            Logger::LogFatal(std::format(
                "Size mismatch error. Given files size: {}. Meanings size: {}", files.size(), requiredSize));
            throw std::runtime_error("Sizes of files and meanings are not equal.");
        }


        std::unordered_set<std::string> uniqueTitles;
        std::unordered_map<std::string, SefariaTranslationFile> nonNullFilesMap;

        for (auto &optionalFile: files) {
            if (optionalFile.has_value()) {
                SefariaTranslationFile file = std::move(optionalFile.value());
                std::string title = file.getTitle();

                if (uniqueTitles.contains(title)) {
                    Logger::LogFatal(std::format(
                        "Uniqueness error. Duplicate file title found: '{}'.", title));
                    throw std::runtime_error("Files must have unique non-null titles.");
                }
                uniqueTitles.insert(title);

                if (auto it = std::ranges::find(meanings, title); it == meanings.cend()) {
                    Logger::LogFatal(std::format(
                        "Title mismatch error. File title '{}' found in files but not in meanings.", title));
                    throw std::runtime_error("Non-null file title must exist in meanings list.");
                }

                nonNullFilesMap.emplace(title, std::move(file));
            }
        }


        std::vector<std::optional<SefariaTranslationFile> > sortedFiles;
        sortedFiles.reserve(requiredSize);

        for (const auto &requiredTitle: meanings) {
            if (auto it = nonNullFilesMap.find(requiredTitle); it != nonNullFilesMap.end())
                sortedFiles.emplace_back(std::move(it->second));
            else
                sortedFiles.emplace_back(std::nullopt);
        }


        return sortedFiles;
    }
} // scrptm
