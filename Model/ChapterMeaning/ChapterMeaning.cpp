//
// Created by prag on 11/6/25.
//

#include "ChapterMeaning.h"

const std::string_view ChapterMeaning::getMeaning() const {
    return this->meaning;
}

const Language &ChapterMeaning::getLanguage() const {
    return this->language;
}

