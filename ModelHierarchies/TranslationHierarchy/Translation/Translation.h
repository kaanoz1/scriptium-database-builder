#ifndef SCRIPTIUM_DATABASE_BUILDER_TRANSLATION_H
#define SCRIPTIUM_DATABASE_BUILDER_TRANSLATION_H
#include <optional>
#include <string>
#include <vector>

#include "../../ScriptureHierarchy/Scripture/Scripture.h"
#include "../TranslationText/TranslationText.h"
#include "../Translator/Translator.h"

namespace scrptm {
    class Translation {
        std::string name;
        const std::optional<std::string> url;

        const std::vector<Translator> translators;
        const std::vector<TranslationText> translationTexts;

        const Language &language;
        const ScriptureIndicator scriptureIndicator;

    public:
        Translation(std::string &&name, std::optional<std::string> &&url, std::vector<Translator> &&translators,
                    std::vector<TranslationText> &&translationTexts, ScriptureIndicator &&scriptureIndicator,
                    const Language &language);


        std::string copyName() const;

        std::optional<std::string> copyUrl() const;

        const std::vector<Translator> &getTranslators() const;

        const std::vector<TranslationText> &getTranslationTexts() const;

        const Language &getLanguage() const;

        const ScriptureIndicator &getScriptureIndicator() const;
    };
} // scrptm

#endif
