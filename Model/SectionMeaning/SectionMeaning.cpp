//
// Created by prag on 11/6/25.
//

#include "SectionMeaning.h"


const std::string_view SectionMeaning::getMeaning() const {
    return this->meaning;
}

const Language &SectionMeaning::getLanguage() const {
    return this->language;
}

