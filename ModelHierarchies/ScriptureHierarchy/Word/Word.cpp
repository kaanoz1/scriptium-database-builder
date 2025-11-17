//
// Created by prag on 11/6/25.
//

#include "Word.h"

namespace scrptm {
    Word::Word(const unsigned int sequence_number, const std::string_view text,
               const std::string_view text_without_vowel,
               const std::string_view text_simplified,
               const std::pmr::vector<std::reference_wrapper<Root> > &roots) : sequence_number(sequence_number),
                                                                               text(text),
                                                                               textWithoutVowel(text_without_vowel),
                                                                               textSimplified(text_simplified),
                                                                               roots(roots) {
    }


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
}
