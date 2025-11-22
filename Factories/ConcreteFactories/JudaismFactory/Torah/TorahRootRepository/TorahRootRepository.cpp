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
            const auto own = this->rootMap.at(latinNumber);

            return std::make_unique<Root>(std::to_string(latinNumber), std::move(own));
        } catch (const std::out_of_range &e) {
            const std::string full_msg = "Root string not found for number " + std::to_string(latinNumber) + ". Details: " + e
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


        return std::move(data["mapping"]);
    }


    void TorahRootRepository::fillMap(const json &source) {
        unsigned int rootInsertedCount = 0;

        for (const auto &[key, value] : source.items()) {
            auto mappingValue = value.get<std::string>();
            unsigned int headerNumber = extractHeader(mappingValue);
            rootMap[headerNumber] = key;

            Logger::LogInformation(std::format("The root ({}\u200e, {}) successfully inserted. Total fetched root: {}",
                                               key, headerNumber, ++rootInsertedCount));
        }
    }

    void TorahRootRepository::validateJson(const json &source) const {
        if (!source.is_object()) {
            const std::string full_msg = "JSON root element must be an object (map), but found " + std::string(source.type_name());
            Logger::LogFatal(full_msg);
            throw std::runtime_error("JSON Structure Invalid");
        }


        for (const auto &[key, value] : source.items()) {

            if (!value.is_string()) {
                const std::string full_msg =
                    "Mapping value for key '" + key + "' must be a string (H{number}), but found type: " + std::string(value.type_name());
                Logger::LogFatal(full_msg);
                throw std::runtime_error("JSON Structure Invalid");
            }
        }

    }

    unsigned int TorahRootRepository::extractHeader(const std::string &mappingValue) {
        const std::regex header_regex("^H(\\d+)$");

        if (std::smatch match; std::regex_match(mappingValue, match, header_regex)) {
            try {
                return std::stoul(match[1].str());
            } catch (const std::exception &e) {
                const std::string full_msg = "Failed to convert string to number for value: " + match[1].str() + ". Error: " +
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
