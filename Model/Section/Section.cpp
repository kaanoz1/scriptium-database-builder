//
// Created by prag on 11/6/25.
//

#include "Section.h"

const std::string_view Section::getName() const {
    return this->name;
}

const unsigned short Section::getNumber() const {
    return this->number;
}

const std::pmr::vector<std::reference_wrapper<Chapter> > &Section::getChapters() const {
    return this-> chapters;
}

const std::pmr::vector<std::reference_wrapper<SectionMeaning> > &Section::getMeanings() const {
    return this->meanings;
}
