//
// Created by prag on 11/6/25.
//

#include "ScriptureMeaning.h"

ScriptureMeaning::ScriptureMeaning(std::string_view meaning, const Language &language)
        : meaning(meaning),
          language(language) {
}


const std::string_view ScriptureMeaning::getMeaning() const {
    return this->meaning;
}

const Language &ScriptureMeaning::getLanguage() const {
    return this->language;
}

