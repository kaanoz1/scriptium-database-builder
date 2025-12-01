#ifndef SCRIPTIUM_DATABASE_BUILDER_SEFARIATRANSLATIONFILESORTER_H
#define SCRIPTIUM_DATABASE_BUILDER_SEFARIATRANSLATIONFILESORTER_H
#include <optional>
#include <string>
#include <vector>

#include "../SefariaTranslationFile/SefariaTranslationFile.h"

namespace scrptm {
    class SefariaTranslationFileSorter {
    public:
        const static std::vector<std::string> meanings;



        std::vector<std::optional<SefariaTranslationFile>> sort(std::vector<std::optional<SefariaTranslationFile>>&& files);
    };
} // scrptm

#endif
