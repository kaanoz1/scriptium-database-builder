#ifndef SCRIPTIUM_DATABASE_BUILDER_SEFARIATRANSLATIONFILESORTER_H
#define SCRIPTIUM_DATABASE_BUILDER_SEFARIATRANSLATIONFILESORTER_H
#include <string>
#include <vector>

#include "../SefariaTranslationFile/SefariaTranslationFile.h"

namespace scrptm {
    class SefariaTranslationFileSorter {
    public:
        const static std::vector<std::string> meanings;



        std::vector<SefariaTranslationFile> sort(std::vector<SefariaTranslationFile>&& files);
    };
} // scrptm

#endif
