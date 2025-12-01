#ifndef SCRIPTIUM_DATABASE_BUILDER_SEFARIATRANSLATIONFILEEXTRACTOR_H
#define SCRIPTIUM_DATABASE_BUILDER_SEFARIATRANSLATIONFILEEXTRACTOR_H
#include <vector>

#include "../SefariaTranslationFile/SefariaTranslationFile.h"

namespace scrptm {
    using json = nlohmann::json;

    class SefariaTranslationFileExtractor {
        const std::string envName = "SEFARIA_TRANSLATION_FOLDER_PATH";
        const char *path = getenv(envName.c_str());

    public:
        SefariaTranslationFileExtractor();

        std::vector<SefariaTranslationFile> extract(std::string translationName) const;
    };
} // scrptm

#endif
