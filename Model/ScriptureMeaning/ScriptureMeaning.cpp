//
// Created by prag on 11/6/25.
//

#include "ScriptureMeaning.h"


const std::string_view ScriptureMeaning::getMeaning() const {
    return this->meaning;
}

const Language &ScriptureMeaning::getLanguage() const {
    return this->language;
}

