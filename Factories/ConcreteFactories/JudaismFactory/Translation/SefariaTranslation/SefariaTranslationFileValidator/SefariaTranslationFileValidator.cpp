#include "SefariaTranslationFileValidator.h"
#include <format>
#include <stdexcept>
#include <nlohmann/json.hpp>
#include "../../../../../../Utils/Logger/Logger.h"

namespace scrptm {
    std::string SefariaTranslationFileValidator::getTitleInfo(const json &js, const std::string &key) const {
        if (js.contains(key) && js[key].is_string()) {
            return js[key].get<std::string>();
        }
        return "N/A or Invalid";
    }

    void SefariaTranslationFileValidator::validateTextStructure(const json &js, const std::string &title,
                                                                const std::string &versionTitle) const {
        if (!js.contains("text") || !js["text"].is_array()) {
            Logger::LogFatal(std::format(
                "JSON object must contain a valid 'text' field which is an array. Title: {}. VersionTitle: {}",
                title,
                versionTitle
            ));
            throw std::runtime_error("Invalid JSON structure: 'text' field is missing or not an array.");
        }

        try {
            const auto &text_array = js["text"];

            for (size_t i = 0; i < text_array.size(); ++i) {
                const auto &inner_array = text_array.at(i);

                if (!inner_array.is_array()) {
                    Logger::LogFatal(std::format(
                        "The element at index {} in the 'text' array is not an array. Title: {}. VersionTitle: {}",
                        i, title, versionTitle
                    ));
                    throw std::runtime_error("Invalid JSON structure: Elements inside 'text' must be arrays.");
                }

                for (size_t j = 0; j < inner_array.size(); ++j) {
                    if (!inner_array.at(j).is_string()) {
                        Logger::LogFatal(std::format(
                            "The element at index [{}][{}] in 'text' is not a string. Title: {}. VersionTitle: {}",
                            i, j, title, versionTitle
                        ));
                        throw std::runtime_error("Invalid JSON structure: Content inside 'text' must be strings.");
                    }
                }
            }
        } catch (const nlohmann::detail::exception &e) {
            Logger::LogFatal(std::format(
                "Unexpected type/index error occurred in JSON 'text' field: {}. Title: {}. VersionTitle: {}",
                e.what(), title, versionTitle
            ));
            throw std::runtime_error("Unexpected error in JSON 'text' field structure.");
        }
    }

    void SefariaTranslationFileValidator::validate(const json &js) const {
        const std::string title = getTitleInfo(js, "title");
        const std::string versionTitle = getTitleInfo(js, "versionTitle");

        if (!js.contains("title") || !js["title"].is_string()) {
            Logger::LogFatal(std::format(
                "JSON object must contain a valid string field 'title'. Current title status: {}. VersionTitle: {}",
                js.contains("title") ? js["title"].dump() : "Missing",
                versionTitle
            ));
            throw std::runtime_error("Invalid JSON structure: 'title' field is missing or not a string.");
        }

        if (!js.contains("versionTitle") || !js["versionTitle"].is_string()) {
            Logger::LogFatal(std::format(
                "JSON object must contain a valid string field 'versionTitle'. Title: {}. Current versionTitle status: {}",
                title,
                js.contains("versionTitle") ? js["versionTitle"].dump() : "Missing"
            ));
            throw std::runtime_error("Invalid JSON structure: 'versionTitle' field is missing or not a string.");
        }

        validateTextStructure(js, title, versionTitle);
    }
} // scrptm
