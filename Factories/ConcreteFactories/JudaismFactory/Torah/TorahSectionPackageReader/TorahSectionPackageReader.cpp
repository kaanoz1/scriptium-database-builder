#include "TorahSectionPackageReader.h"

#include <filesystem>
#include <fstream>
#include <memory>
#include <string>
#include <format>
#include "../../../../../Utils/Logger/Logger.h"

namespace scrptm {
    TorahSectionPackageReader::TorahSectionPackageReader(const std::string_view path,
                                                         const unsigned char sectionCount) : path(path),
        sectionCount(sectionCount) {
    }

    std::unique_ptr<const json> TorahSectionPackageReader::readJsonFile(const std::filesystem::path &filePath) {
        std::ifstream ifs(filePath);

        if (!ifs.is_open()) {
            std::string errorMsg = std::format("JSON file could not open: {}", filePath.string());
            Logger::LogFatal(errorMsg);

            throw std::runtime_error(errorMsg);
        }

        auto j_ptr = std::make_unique<json>();

        try {
            ifs >> *j_ptr;
        } catch (const json::parse_error &e) {
            std::string errorMsg = std::format("FATAL: JSON could not be parsed: (\"{}\"): {}",
                                               filePath.string(),
                                               e.what());
            Logger::LogFatal(errorMsg);
            throw;
        } catch (const std::exception &e) {
            std::string errorMsg = std::format("Unexpected error while reading JSON: (\"{}\"): {}",
                                               filePath.string(),
                                               e.what());
            Logger::LogFatal(errorMsg);
            throw;
        }

        Logger::LogInformation(std::format("The file is successfully read. File path: .../{}/{}",
                                           filePath.parent_path().filename().string(),
                                           filePath.filename().string()));


        return j_ptr;
    }

    std::unique_ptr<const xml> TorahSectionPackageReader::readXmlFile(const std::filesystem::path &filePath) {
        auto doc_ptr = std::make_unique<xml>();
        try {
            if (pugi::xml_parse_result result = doc_ptr->load_file(filePath.string().c_str()); !result) {
                const std::string errorMsg = std::format(
                    "XML file could not be loaded (\"{}\"): Error: {}; Offset: {}",
                    filePath.string(),
                    result.description(),
                    result.offset
                );
                Logger::LogFatal(errorMsg);

                throw std::runtime_error(errorMsg);
            }
        } catch (const std::exception &e) {
            const std::string errorMsg = std::format(
                "Unexpected error while reading XML file (\"{}\"): {}",
                filePath.string(),
                e.what()
            );
            Logger::LogFatal(errorMsg);
            throw;
        }

        Logger::LogInformation(std::format("The file is successfully read. File path: .../{}/{}",
                                           filePath.parent_path().filename().string(),
                                           filePath.filename().string()));
        return doc_ptr;
    }

    std::unique_ptr<TorahVariationFile> TorahSectionPackageReader::readVariationFile(
        std::unique_ptr<const json> &&json) {
        if (json == nullptr)
            throw std::runtime_error("JSON file is null");

        auto sectionNameInHebrew{json->at("heTitle").get<std::string>()};
        auto sectionTitleEnglish{json->at("title").get<std::string>()};

        const std::vector<std::vector<std::string> > text = json->at("text").get<std::vector<std::vector<
            std::string> > >();


        std::vector<std::unique_ptr<TorahRawChapter> > chapters{};

        chapters.reserve(text.size());

        for (size_t i = 0; i < text.size(); ++i) {
            const std::vector<std::string> &chapter = text.at(i);


            std::vector<std::unique_ptr<TorahRawVerse> > verses;
            for (size_t j = 0; j < chapter.size(); ++j) {
                const std::string &verse = chapter.at(j);

                verses.emplace_back(std::make_unique<TorahRawVerse>(j, verse));
            }

            chapters.emplace_back(
                std::make_unique<TorahRawChapter>(static_cast<unsigned char>(i), std::move(verses)));
        }

        Logger::LogInformation(std::format("TorahVariationFile is constructed!"));
        return std::make_unique<
            TorahVariationFile>(std::move(sectionNameInHebrew), std::move(sectionTitleEnglish), std::move(chapters));
    }

    std::unique_ptr<TorahSectionWordFile> TorahSectionPackageReader::readWordFile(
        std::unique_ptr<const xml> &&xml) {
        if (!xml) {
            throw std::runtime_error("XML Document is null.");
        }

        const auto osis = xml->child("osis");

        if (!osis) {
            Logger::LogFatal("FATAL: osis root node could not be found.");
            throw std::runtime_error("osis root node could not be found");
        }

        const auto osisText = osis.child("osisText");
        if (!osisText) {
            Logger::LogFatal("FATAL: osisText node could not be found.");
            throw std::runtime_error("osisText node could not be found");
        }

        const auto div = osisText.child("div");
        if (!div) {
            Logger::LogFatal("FATAL: div node could not be found");
            throw std::runtime_error("div node could not be found");
        }


        std::vector<std::unique_ptr<TorahRawChapterOfWordFile> > chapters{};

        const auto chapterNodes = div.children("chapter");
        const auto chapterCount = static_cast<size_t>(std::distance(chapterNodes.begin(), chapterNodes.end()));

        for (size_t chapterIndex = 0; chapterIndex < chapterCount; ++chapterIndex) {
            pugi::xml_node chapter_node = *std::next(chapterNodes.begin(), static_cast<ptrdiff_t>(chapterIndex));

            std::vector<std::unique_ptr<TorahRawVerseOfWordFile> > verses{};

            auto verseNodes = chapter_node.children("verse");
            const size_t verseCount = std::distance(verseNodes.begin(), verseNodes.end());

            for (size_t verseIndex = 0; verseIndex < verseCount; ++verseIndex) {
                pugi::xml_node verse_node = *std::next(verseNodes.begin(), static_cast<ptrdiff_t>(verseIndex));

                std::vector<std::unique_ptr<TorahRawWord> > words{};

                auto wordNodes = verse_node.children("w");
                const size_t wordCount = std::distance(wordNodes.begin(), wordNodes.end());

                for (size_t wordIndex = 0; wordIndex < wordCount; ++wordIndex) {
                    pugi::xml_node word_node = *std::next(wordNodes.begin(), static_cast<ptrdiff_t>(wordIndex));

                    words.emplace_back(std::make_unique<TorahRawWord>(
                        word_node.text().get(),
                        word_node.attribute("lemma").as_string(),
                        static_cast<unsigned int>(wordIndex)
                    ));
                }

                verses.emplace_back(std::make_unique<TorahRawVerseOfWordFile>(
                    static_cast<unsigned int>(verseIndex),
                    std::move(words)
                ));
            }

            chapters.emplace_back(std::make_unique<TorahRawChapterOfWordFile>(
                static_cast<unsigned int>(chapterIndex),
                std::move(verses)
            ));
        }


        Logger::LogInformation(std::format("TorahSectionWordFile constructed!"));
        return std::make_unique<TorahSectionWordFile>(std::move(chapters));
    }


    void TorahSectionPackageReader::validateJsonFile(const json &j, std::string_view fileName) {
        try {
            if (!j.at("title").is_string()) {
                throw std::runtime_error("Field 'title' found but is not a string.");
            }
            if (!j.at("heTitle").is_string()) {
                throw std::runtime_error("Field 'heTitle' found but is not a string.");
            }

            if (!j.at("text").is_array()) {
                throw std::runtime_error("Field 'text' not found or is not an array.");
            }

            for (const auto &chapter_array: j.at("text")) {
                if (!chapter_array.is_array()) {
                    throw std::runtime_error("Elements within 'text' (chapters) are not arrays.");
                }
                for (const auto &verse_string: chapter_array) {
                    if (!verse_string.is_string()) {
                        throw std::runtime_error("Elements within chapter arrays (verses) are not strings.");
                    }
                }
            }
            Logger::LogInformation(std::format("JSON file validated. File name: {}", fileName));
        } catch (const json::out_of_range &e) {
            const std::string errorMsg = std::format("FATAL: JSON structure error in {}. Required field missing: {}",
                                                     fileName, e.what());
            Logger::LogFatal(errorMsg);
            throw std::runtime_error(errorMsg);
        } catch (const std::exception &e) {
            const std::string errorMsg = std::format("FATAL: Unexpected error during JSON validation for {}: {}",
                                                     fileName, e.what());
            Logger::LogFatal(errorMsg);
            throw std::runtime_error(errorMsg);
        }
    }

    void TorahSectionPackageReader::validateXmlFile(const xml &doc, unsigned char sectionPackageNumber) {
        try {
            const pugi::xml_node osis = doc.child("osis");
            if (!osis) { throw std::runtime_error("XML structure error: Missing 'osis' root node."); }

            const pugi::xml_node osisText = osis.child("osisText");
            if (!osisText) { throw std::runtime_error("XML structure error: Missing 'osisText' node under 'osis'."); }

            const pugi::xml_node div = osisText.child("div");
            if (!div) { throw std::runtime_error("XML structure error: Missing 'div' node under 'osisText'."); }

            for (pugi::xml_node chapter_node: div.children("chapter")) {
                if (chapter_node.empty()) { throw std::runtime_error("XML structure error: Chapter node is empty."); }

                for (pugi::xml_node verse_node: chapter_node.children("verse")) {
                    if (verse_node.empty()) { throw std::runtime_error("XML structure error: Verse node is empty."); }

                    for (pugi::xml_node w_node: verse_node.children("w")) {
                        if (w_node.text().empty()) {
                            throw std::runtime_error(std::format(
                                "XML structure error: 'w' tag content is missing (Node: {}).", w_node.name()));
                        }

                        if (!w_node.attribute("lemma")) {
                            throw std::runtime_error(std::format(
                                "XML structure error: Missing 'lemma' attribute in 'w' tag (Node: {}).",
                                w_node.name()));
                        }
                    }
                }
            }
            Logger::LogInformation(std::format("XML file validated. File name: {}",
                                               std::to_string(sectionPackageNumber) + ".xml"));
        } catch (const std::exception &e) {
            const std::string errorMsg = std::format("FATAL: Unexpected error during XML validation for {}: {}",
                                                     sectionPackageNumber, e.what());
            Logger::LogFatal(errorMsg);
            throw std::runtime_error(errorMsg);
        }
    }

    void TorahSectionPackageReader::validateFileContent(const json &usualFileJson, const json &simplifiedJsonFile,
                                                        const json &noVowelJsonFile, const xml &wordXmlFile,
                                                        const unsigned char sectionPackageNumber) {
        validateJsonFile(usualFileJson, "usual.json");
        validateJsonFile(simplifiedJsonFile, "simplified.json");
        validateJsonFile(noVowelJsonFile, "noVowel.json");

        validateXmlFile(wordXmlFile, sectionPackageNumber);
    }


    //TODO: Mark this function as const.
    std::vector<std::unique_ptr<TorahSectionPackage> > TorahSectionPackageReader::read() const {
        std::vector<std::unique_ptr<TorahSectionPackage> > result;


        result.reserve(this->sectionCount);

        const std::filesystem::path basePath(this->path.begin(), this->path.end());

        for (size_t i = 1; i <= this->sectionCount; ++i) {
            const std::filesystem::path sectionPackageFolderPath = basePath / std::to_string(i);

            const std::filesystem::path usualJsonFilePath = sectionPackageFolderPath / "usual.json";
            const std::filesystem::path simplifiedJsonFilePath = sectionPackageFolderPath / "simplified.json";
            const std::filesystem::path noVowelJsonFilePath = sectionPackageFolderPath / "noVowel.json";
            const std::filesystem::path wordFileXmlPath = sectionPackageFolderPath / (std::to_string(i) + ".xml");


            std::unique_ptr<const json> usualFileJson = readJsonFile(usualJsonFilePath);
            std::unique_ptr<const json> simplifiedFileJson = readJsonFile(simplifiedJsonFilePath);
            std::unique_ptr<const json> noVowelFileJson = readJsonFile(noVowelJsonFilePath);
            std::unique_ptr<const xml> xmlFile = readXmlFile(wordFileXmlPath);

            validateFileContent(*usualFileJson, *simplifiedFileJson, *noVowelFileJson, *xmlFile,
                                static_cast<unsigned char>(i));

            std::unique_ptr<TorahVariationFile> usualFile = readVariationFile(std::move(usualFileJson));
            std::unique_ptr<TorahVariationFile> simplifiedFile = readVariationFile(
                std::move(simplifiedFileJson));
            std::unique_ptr<TorahVariationFile> noVowelFile = readVariationFile(std::move(noVowelFileJson));
            std::unique_ptr<TorahSectionWordFile> wordFile = readWordFile(std::move(xmlFile));

            Logger::LogDebug(std::format("Section {} package is created", i));

            auto package =
                    std::make_unique<TorahSectionPackage>(
                        std::move(usualFile),
                        std::move(simplifiedFile),
                        std::move(noVowelFile),
                        std::move(wordFile)
                    );

            result.emplace_back(std::move(package));
        }
        return std::move(result);
    }
} // scrptm
