//
// Created by prag on 11/6/25.
//

#include "Language.h"

Language::Language(std::string_view lang_own, std::string_view lang_english, std::string_view lang_code)
    : langOwn(lang_own),
      langEnglish(lang_english),
      langCode(lang_code) {
}


const std::string_view Language::getLanguageCode() const {
    return this->langCode;
}

const std::string_view Language::getLanguageEnglish() const {
    return this->langEnglish;
}

const std::string_view Language::getLanguageOwn() const {
    return this->langOwn;
}
