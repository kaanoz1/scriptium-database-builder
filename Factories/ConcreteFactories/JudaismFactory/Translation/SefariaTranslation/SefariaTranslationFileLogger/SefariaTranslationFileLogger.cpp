#include "SefariaTranslationFileLogger.h"

#include <format>
#include <optional>

#include "../../../../../../Utils/Logger/Logger.h"

namespace scrptm {
    void SefariaTranslationFileLogger::log(const std::vector<std::optional<SefariaTranslationFile> > &files) const {
        const size_t fileCount = files.size();
        const size_t meaningCount = meanings.size();

        if (fileCount != meaningCount) {
            Logger::LogFatal(std::format(
                "File count is not equal with meaning count whereas it should be. FileCount: {}, MeaningCount: {}",
                fileCount, meaningCount));
            throw std::runtime_error("File count is not equal with meaning count");
        }

        for (size_t i = 0; i < meaningCount; i++) {
            std::string meaning = meanings.at(i);
            const std::optional<SefariaTranslationFile> &file = files.at(i);

            if (file.has_value() && file.value().getTitle() != meaning) {
                Logger::LogFatal(std::format(
                    "Title is not same as meaning. Whereas it should be. title[i]: {}, meanings[i]: {}. Where i: {}",
                    file.value().getTitle(), meaning, i));
                throw std::runtime_error("Title is not same as meanings");
            }


            std::cout << std::format("m: {} - t: {}, exist?: {}", meaning,
                                     file.has_value() ? file.value().getTitle() : "Unknown", file.has_value()) << std::endl;

        }
    }
} // scrptm
