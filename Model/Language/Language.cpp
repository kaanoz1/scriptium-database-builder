//
// Created by prag on 11/6/25.
//

#include "Language.h"

const std::string_view Language::getLanguageCode() const {
    return this->langCode;
}

const std::string_view Language::getLanguageEnglish() const {
    return this->langEnglish;
}

const std::string_view Language::getLanguageOwn() const {
    return this->langOwn;
}
