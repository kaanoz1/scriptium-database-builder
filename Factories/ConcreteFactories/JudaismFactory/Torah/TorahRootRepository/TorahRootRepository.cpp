#include "TorahRootRepository.h"

#include <format>
#include <fstream>
#include <regex>
#include <nlohmann/json.hpp>
#include <stdexcept>
#include <string>
#include "../../../../../Utils/Logger/Logger.h"


using json = nlohmann::json;


namespace scrptm {
    TorahRootRepository::TorahRootRepository() {
        const json source = readSourceFile();
        validateJson(source);
        fillMap(source);
    }

    std::unique_ptr<Root> TorahRootRepository::find(const unsigned int latinNumber) const {
        try {

            if (latinNumber == 0)
                return nullptr;

            const auto own = this->rootMap.at(latinNumber);

            return std::make_unique<Root>(std::to_string(latinNumber), std::move(own));
        } catch (const std::out_of_range &e) {
            const std::string full_msg = "Root string not found for number " + std::to_string(latinNumber) +
                                         ". Details: " + e
                                         .what();
            Logger::LogFatal(full_msg);
            throw std::out_of_range("Not Found");
        }
    }

    json TorahRootRepository::readSourceFile() const {
        std::ifstream file(this->sourceFilePath);
        if (!file.is_open()) {
            std::string full_msg = "File could not be opened at path: " + this->sourceFilePath;
            Logger::LogFatal(full_msg);
            throw std::runtime_error("File Open Failed");
        }

        json data;

        try {
            file >> data;
        } catch (const json::parse_error &e) {
            std::string full_msg = "JSON could not be parsed. Error: " + std::string(e.what());
            Logger::LogFatal(full_msg);
            throw std::runtime_error("JSON Parse Failed");
        }


        if (data.count("dict") == 0) {
            std::string full_msg = "Required 'dict' property not found in the source JSON file.";
            Logger::LogFatal(full_msg);
            throw std::runtime_error("JSON Dict Property Missing");
        }

        return std::move(data["dict"]);
    }


    void TorahRootRepository::fillMap(const json &source) {
        unsigned int rootInsertedCount = 0;

        for (const auto &[key, value]: source.items()) {
            auto val = value["w"]["w"].get<std::string>();
            unsigned int headerNumber = extractHeader(key);
            rootMap[headerNumber] = val;

            Logger::LogInformation(std::format(
                "The root ({}\u200e, {}) successfully inserted. For key: {}. Total fetched root: {}",
                headerNumber, val, key, ++rootInsertedCount));
        }
    }

    void TorahRootRepository::validateJson(const json &source) const {
        if (!source.is_object()) {
            const std::string full_msg =
                    std::format("JSON root element ('dict') must be an object (map), but found {}",
                                source.type_name());
            Logger::LogFatal(full_msg);
            throw std::runtime_error("JSON Structure Invalid: Root is not an object");
        }


        for (const auto &[key, value]: source.items()) {
            if (!value.is_object()) {
                const std::string full_msg =
                        std::format("Root entry '{}' must be an object, but found type: {}",
                                    key, value.type_name());
                Logger::LogFatal(full_msg);
                throw std::runtime_error("JSON Structure Invalid: Root entry is not an object");
            }


            if (!value.contains("w") || !value["w"].is_object()) {
                const std::string full_msg =
                        std::format("Root entry '{}' is missing the mandatory 'w' object.", key);
                Logger::LogFatal(full_msg);
                throw std::runtime_error("JSON Structure Invalid: Missing 'w' object");
            }

            if (!value["w"].contains("lemma") && !value["w"].contains("pos") && !value["w"].contains("w")) {
                const std::string full_msg =
                        std::format("Root entry '{}' 'w' object is missing core fields.", key);
                Logger::LogFatal(full_msg);
                throw std::runtime_error("JSON Structure Invalid: Missing core fields in 'w'");
            }

            if (!value.contains("meaning") || !value.contains("usage") || !value.contains("source")) {
                const std::string full_msg =
                        std::format(
                            "Root entry '{}' is missing one of the mandatory top-level fields (meaning, usage, source).",
                            key);
                Logger::LogFatal(full_msg);
                throw std::runtime_error("JSON Structure Invalid: Missing top-level fields");
            }
        }
    }

    unsigned int TorahRootRepository::extractHeader(const std::string &mappingValue) {
        const std::regex header_regex("^H(\\d+)$");

        if (std::smatch match; std::regex_match(mappingValue, match, header_regex)) {
            try {
                return std::stoul(match[1].str());
            } catch (const std::exception &e) {
                const std::string full_msg = "Failed to convert string to number for value: " + match[1].str() +
                                             ". Error: " +
                                             e.what();
                Logger::LogFatal(full_msg);
                throw std::runtime_error("Conversion Failed");
            }
        }

        const std::string full_msg = "Unexpected mapping format. Expected H{number}, but got: " + mappingValue;
        Logger::LogFatal(full_msg);
        throw std::runtime_error("Format Mismatch");
    }
} // scrptm
