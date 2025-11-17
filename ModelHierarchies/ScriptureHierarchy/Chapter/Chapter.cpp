//
// Created by prag on 11/6/25.
//

#include "Chapter.h"

Chapter::Chapter(unsigned short number, std::string_view name,
                 const std::pmr::vector<std::reference_wrapper<Verse> > &verses,
                 const std::pmr::vector<std::reference_wrapper<ChapterMeaning> > &meanings) : number(number),
    name(name),
    verses(verses),
    meanings(meanings) {
}


const std::string_view Chapter::getName() const {
    return this->name;
}

const unsigned short Chapter::getNumber() const {
    return this->number;
}

const std::pmr::vector<std::reference_wrapper<Verse> > &Chapter::getVerses() const {
    return this->verses;
}

const std::pmr::vector<std::reference_wrapper<ChapterMeaning> > &Chapter::getMeanings() const {
    return this->meanings;
}
