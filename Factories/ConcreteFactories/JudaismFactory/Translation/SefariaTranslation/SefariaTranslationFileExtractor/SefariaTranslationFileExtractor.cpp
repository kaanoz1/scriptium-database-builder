#include "SefariaTranslationFileExtractor.h"

#include <format>
#include <fstream>
#include <filesystem>
#include <vector>
#include <optional>
#include <stdexcept>

#include "../../../../../../Utils/Logger/Logger.h"
#include "../SefariaTranslationFileSorter/SefariaTranslationFileSorter.h"
#include "../SefariaTranslationFileValidator/SefariaTranslationFileValidator.h"
#include <nlohmann/json.hpp>

namespace scrptm {
    using json = nlohmann::json;

    SefariaTranslationFileExtractor::SefariaTranslationFileExtractor() {
        if (this->path == nullptr) {
            Logger::LogFatal(std::format("path is null. Check the the envName: {}", envName));
            throw std::invalid_argument(std::format("path is null. Check the the envName: {}", envName));
        }
    }

    std::vector<SefariaTranslationFile> SefariaTranslationFileExtractor::extract(
        const std::string translationName) const {
        namespace fs = std::filesystem;

        size_t folderCount = SefariaTranslationFileSorter::meanings.size();

        std::vector<std::optional<SefariaTranslationFile> > optionalFiles;

        fs::path rootPath(this->path);

        std::vector<fs::path> subFolders;

        try {
            for (const auto &entry: fs::directory_iterator(rootPath)) {
                if (entry.is_directory()) {
                    subFolders.push_back(entry.path());
                }
            }
        } catch (const fs::filesystem_error &e) {
            Logger::LogError(std::format("Filesystem access error: {}", e.what()));
            throw;
        }

        if (subFolders.size() != folderCount) {
            std::string errMsg = std::format(
                "Mismatch in folder count under path: '{}'. Expected: {}, Found: {}.",
                rootPath.string(), folderCount, subFolders.size()
            );
            Logger::LogError(errMsg);
            throw std::runtime_error(errMsg);
        }

        Logger::LogInformation(std::format("Success: Found expected {} subfolders in the root directory.",
                                           folderCount));


        const fs::path englishFolderName = "English";
        const std::string targetFileName = std::format("{}.json", translationName);

        for (const auto &folderPath: subFolders) {
            fs::path englishPath = folderPath / englishFolderName;

            if (!fs::exists(englishPath) || !fs::is_directory(englishPath)) {
                std::string errMsg = std::format(
                    "Error: Expected 'English' folder not found inside '{}'.",
                    folderPath.string()
                );
                Logger::LogError(errMsg);
                throw std::runtime_error(errMsg);
            }

            fs::path jsonFilePath = englishPath / targetFileName;

            if (!fs::exists(jsonFilePath) || !fs::is_regular_file(jsonFilePath)) {
                Logger::LogWarning(std::format("Warning: Target file '{}' not found under '{}'. Null added.",
                                               targetFileName, englishPath.string()));
                optionalFiles.push_back(std::nullopt);
                continue;
            }

            try {
                SefariaTranslationFileValidator validator;

                std::ifstream ifs(jsonFilePath);
                if (!ifs.is_open()) {
                    throw std::runtime_error(std::format("Could not open JSON file: {}", jsonFilePath.string()));
                }

                json j;
                ifs >> j;

                validator.validate(j);

                optionalFiles.push_back(SefariaTranslationFile(std::move(j)));
                Logger::LogInformation(std::format("Success: File '{}' processed and added.",
                                                   jsonFilePath.string()));
            } catch (const json::parse_error &e) {
                Logger::LogError(std::format("JSON Parsing Error (nlohmann/json): {} Path: {}", e.what(),
                                             jsonFilePath.string()));
                optionalFiles.push_back(std::nullopt);
            } catch (const std::exception &e) {
                Logger::LogError(
                    std::format("JSON File/Validation Error: {} Path: {}", e.what(), jsonFilePath.string()));
                optionalFiles.push_back(std::nullopt);
            }
        }


        std::vector<SefariaTranslationFile> extractedFiles;
        for (auto &optFile: optionalFiles) {
            if (optFile.has_value()) {
                extractedFiles.push_back(std::move(optFile.value()));
            }
        }

        return extractedFiles;
    }
} // scrptm
