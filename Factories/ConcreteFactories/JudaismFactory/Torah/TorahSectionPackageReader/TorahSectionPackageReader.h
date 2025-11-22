#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHSECTIONPACKAGEREADER_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHSECTIONPACKAGEREADER_H
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
#include <pugixml.hpp>

#include <filesystem>
#include "../TorahSectionPackage/TorahSectionPackage.h"

namespace scrptm {
    using json = nlohmann::json;
    using xml = pugi::xml_document;

    class TorahSectionPackageReader {
        const std::string_view path;
        const unsigned char sectionCount;

        static std::unique_ptr<TorahVariationFile> readVariationFile(std::unique_ptr<const json> &&json);

        static std::unique_ptr<TorahSectionWordFile> readWordFile(std::unique_ptr<const xml> &&xml);

        static void validateFileContent(const json &usualFileJson, const json &simplifiedJsonFile,
                                        const json &noVowelJsonFile,
                                        const xml &wordXmlFile, unsigned char sectionPackageNumber);

        static void validateJsonFile(const json &j, std::string_view fileName);

        static void validateXmlFile(const xml &doc, unsigned char sectionPackageNumber);

        static std::unique_ptr<const json> readJsonFile(const std::filesystem::path &filePath);

        static std::unique_ptr<const xml> readXmlFile(const std::filesystem::path &filePath);

    public:
        TorahSectionPackageReader(std::string_view path, unsigned char sectionCount);

        [[nodiscard]] std::vector<std::unique_ptr<TorahSectionPackage> > read() const;
    };
} // scrptm

#endif
