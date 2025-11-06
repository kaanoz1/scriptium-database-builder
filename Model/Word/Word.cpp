//
// Created by prag on 11/6/25.
//

#include "Word.h"

const unsigned int Word::getSequenceNumber() const {
    return this->sequence_number;
}

const std::string_view Word::getText() const {
    return this->text;
}

const std::string_view Word::getTextSimplified() const {
    return this->textSimplified;
}

const std::string_view Word::getTextWithoutVowel() const {
    return this->textWithoutVowel;
}

const std::pmr::vector<std::reference_wrapper<Root> > &Word::getRoots() const {
    return this->roots;
}
