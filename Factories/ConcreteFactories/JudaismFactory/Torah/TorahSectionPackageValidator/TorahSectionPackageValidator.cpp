#include "TorahSectionPackageValidator.h"
#include <filesystem>
#include <string>
#include <format>
#include "../../../../../Utils/Logger/Logger.h"

namespace scrptm {
    TorahSectionPackageValidator::TorahSectionPackageValidator(const std::string_view path,
                                                               const unsigned char sectionCount) : path(path),
        sectionCount(sectionCount) {
    }




    void TorahSectionPackageValidator::validate() const {
        const std::filesystem::path basePath(this->path.begin(), this->path.end());

        // ReSharper disable once CppTooWideScope
        constexpr std::array<const std::string_view, 3> requiredJsonFiles = {
            "usual.json", "simplified.json", "noVowel.json"
        };

        for (unsigned char i = 1; i <= this->sectionCount; ++i) {

            const std::filesystem::path sectionPackageFolderPath = basePath / std::to_string(i);

            if (!std::filesystem::is_directory(sectionPackageFolderPath)) {
                const std::string errorMsg = std::format(
                    "Required directory not found: {}",
                    sectionPackageFolderPath.string()
                );
                Logger::LogFatal(errorMsg);
                throw std::runtime_error("Required directory is missing.");
            }

            for (const auto &fileName: requiredJsonFiles) {
                if (const std::filesystem::path filePath = sectionPackageFolderPath / fileName; !std::filesystem::exists(filePath)) {
                    const std::string errorMsg = std::format(
                        "Required JSON file is missing in {}: {}",
                        sectionPackageFolderPath.string(),
                        fileName
                    );
                    Logger::LogFatal(errorMsg);
                    throw std::runtime_error("Required JSON file is missing.");
                }
            }


            const std::string xmlFileName = std::to_string(i) + ".xml";

            if (const std::filesystem::path xmlFilePath = sectionPackageFolderPath / xmlFileName; !std::filesystem::exists(xmlFilePath)) {
                const std::string errorMsg = std::format(
                    "Required XML file is missing in {}: {}",
                    sectionPackageFolderPath.string(),
                    xmlFileName
                );
                Logger::LogFatal(errorMsg);
                throw std::runtime_error("Required XML file is missing.");
            }
        }
    }
} // scrptm
