#ifndef SCRIPTIUM_DATABASE_BUILDER_SEFARIATRANSLATIONFILELOGGER_H
#define SCRIPTIUM_DATABASE_BUILDER_SEFARIATRANSLATIONFILELOGGER_H
#include <optional>
#include <string>
#include <vector>

#include "../SefariaTranslationFileSorter/SefariaTranslationFileSorter.h"

namespace scrptm {
    class SefariaTranslationFileLogger {

        const std::vector<std::string>& meanings = SefariaTranslationFileSorter::meanings;


    public:

        void log(const std::vector<std::optional<SefariaTranslationFile>>& files) const;


    };
} // scrptm

#endif