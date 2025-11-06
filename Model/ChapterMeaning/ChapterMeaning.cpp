//
// Created by prag on 11/6/25.
//

#include "ChapterMeaning.h"

ChapterMeaning::ChapterMeaning(const std::string_view meaning, const Language &language) : meaning(meaning),
    language(language) {
}


const std::string_view ChapterMeaning::getMeaning() const {
    return this->meaning;
}

const Language &ChapterMeaning::getLanguage() const {
    return this->language;
}
