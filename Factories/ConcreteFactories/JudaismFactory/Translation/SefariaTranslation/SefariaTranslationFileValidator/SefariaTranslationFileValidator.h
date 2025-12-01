#ifndef SCRIPTIUM_DATABASE_BUILDER_SEFARIATRANSLATIONFILEVALIDATOR_H
#define SCRIPTIUM_DATABASE_BUILDER_SEFARIATRANSLATIONFILEVALIDATOR_H
#include <nlohmann/adl_serializer.hpp>

namespace scrptm {
    class SefariaTranslationFileValidator {
        using json = nlohmann::json;

    public:
        void validate(const json &js) const;

        std::string getTitleInfo(const json &js, const std::string& key) const;

        void validateTextStructure(const json &js, const std::string& title, const std::string& versionTitle) const;
    };
} // scrptm

#endif
