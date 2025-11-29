
#include "Language.h"

namespace scrptm {
    Language::Language(const std::string_view lang_own, const std::string_view lang_english, const std::string_view lang_code)
        : langOwn(lang_own),
          langEnglish(lang_english),
          langCode(lang_code) {
    }


    const std::string Language::getLanguageCode() const {
        return this->langCode;
    }

    const std::string Language::getLanguageEnglish() const {
        return this->langEnglish;
    }

    const std::string Language::getLanguageOwn() const {
        return this->langOwn;
    }
}
