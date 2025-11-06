//
// Created by prag on 11/6/25.
//

#ifndef SCRIPTIUM_DATABASE_BUILDER_LANGUAGE_H
#define SCRIPTIUM_DATABASE_BUILDER_LANGUAGE_H
#include <string>


class Language {
private:
    const std::string_view langOwn;
    const std::string_view langEnglish;
    const std::string_view langCode;

public:
    Language(const std::string_view lang_own, const std::string_view lang_english, const std::string_view lang_code)
        : langOwn(lang_own),
          langEnglish(lang_english),
          langCode(lang_code) {
    }

    [[nodiscard]] const std::string_view getLanguageCode() const;
    [[nodiscard]] const std::string_view getLanguageOwn() const;
    [[nodiscard]] const std::string_view getLanguageEnglish() const;
};


#endif //SCRIPTIUM_DATABASE_BUILDER_LANGUAGE_H