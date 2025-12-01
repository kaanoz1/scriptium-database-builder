#include "Translation.h"

namespace scrptm {
    Translation::Translation(std::string &&name, std::optional<std::string> &&url,
                             std::vector<Translator> &&translators, std::vector<TranslationText> &&translationTexts,
                             ScriptureIndicator &&scriptureIndicator,
                             const Language &language) : name(name), url(std::move(url)),
                                                         translators(std::move(translators)),
                                                         translationTexts(std::move(translationTexts)),
                                                         language(language),
                                                         scriptureIndicator(
                                                             std::move(scriptureIndicator)) {
    }

    std::string Translation::copyName() const {
        return this->name;
    }

    std::optional<std::string> Translation::copyUrl() const {
        return this->url;
    }

    const Language &Translation::getLanguage() const {
        return this->language;
    }

    const ScriptureIndicator &Translation::getScriptureIndicator() const {
        return this->scriptureIndicator;
    }

    const std::vector<TranslationText> &Translation::getTranslationTexts() const {
        return this->translationTexts;
    }

    const std::vector<Translator> &Translation::getTranslators() const {
        return this->translators;
    }
} // scrptm
