#include "SefariaTranslationFileSorter.h"

#include <format>
#include <unordered_map>

#include "../../../../../../Utils/Logger/Logger.h"

namespace scrptm {
    std::vector<std::string> SefariaTranslationFileSorter::meanings =
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

    std::vector<SefariaTranslationFile>
    SefariaTranslationFileSorter::sort(std::vector<SefariaTranslationFile> &&files) {
        const size_t filesSize = files.size();
        const size_t meaningsSize = meanings.size();

        if (filesSize != meaningsSize) {
            Logger::LogFatal(std::format(
                "Given files and meanings size are not equal. Given array size: {}. Meanings size: {}", filesSize,
                meaningsSize));
            throw std::runtime_error("Sizes are not equal");
        }


        std::unordered_map<std::string, SefariaTranslationFile> fileMap;
        fileMap.reserve(filesSize);
        for (auto& file : files) {
            fileMap.emplace(file.getTitle(), std::move(file));
        }

        std::vector<SefariaTranslationFile> sortedFiles;
        sortedFiles.reserve(filesSize);

        for (const auto& requiredTitle : meanings) {
            auto it = fileMap.find(requiredTitle);

            if (it == fileMap.end()) {
                Logger::LogFatal(std::format("Internal error: Required file '{}' not found in map during sorting.", requiredTitle));
                throw std::runtime_error("Required file not found during sorting");
            }

            sortedFiles.push_back(std::move(it->second));

            fileMap.erase(it);
        }

        return sortedFiles;
    }


} // scrptm
