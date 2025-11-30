#ifndef SCRIPTIUM_DATABASE_BUILDER_TRANSLATIONFILE_H
#define SCRIPTIUM_DATABASE_BUILDER_TRANSLATIONFILE_H
#include <string>
#include <vector>
#include <nlohmann/json_fwd.hpp>

namespace scrptm {
    using json = nlohmann::json;

    class SefariaTranslationFile {
        const std::string sectionName;
        const std::string translatorName;
        std::vector<std::vector<std::string> > texts;

    public:
        explicit SefariaTranslationFile(json translationFile);

        [[nodiscard]] std::string copySectionName() const;

        [[nodiscard]] std::string copyTranslatorName() const;

        [[nodiscard]] std::vector<std::vector<std::string> > copyTexts() const;

        [[nodiscard]] const std::vector<std::vector<std::string> > &getTexts() const;

        std::vector<std::vector<std::string> > giveTexts();
    };
} // scrptm

#endif
