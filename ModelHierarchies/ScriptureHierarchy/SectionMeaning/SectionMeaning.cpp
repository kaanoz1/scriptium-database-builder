//
// Created by prag on 11/6/25.
//

#include "SectionMeaning.h"

SectionMeaning::SectionMeaning(const std::string_view meaning, const Language &language) : meaning(meaning),
    language(language) {
}

const std::string_view SectionMeaning::getMeaning() const {
    return this->meaning;
}

const Language &SectionMeaning::getLanguage() const {
    return this->language;
}
