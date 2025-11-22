#include "Word.h"

#include <algorithm>

namespace scrptm {
    Word::Word(const unsigned int sequence_number, std::string text,
               std::string text_simplified,
               std::string text_without_vowel,
               std::vector<std::unique_ptr<Root> > &&roots) : sequence_number(sequence_number),
                                                              text(std::move(text)),
                                                              textWithoutVowel(std::move(text_without_vowel)),
                                                              textSimplified(std::move(text_simplified)),
                                                              roots(std::move(roots)) {
    }


    unsigned int Word::getSequenceNumber() const {
        return this->sequence_number;
    }

    std::string_view Word::getText() const {
        return this->text;
    }

    std::string_view Word::getTextSimplified() const {
        return this->textSimplified;
    }

    std::string_view Word::getTextWithoutVowel() const {
        return this->textWithoutVowel;
    }

    const std::vector<std::unique_ptr<Root> > &Word::getRoots() const {
        return this->roots;
    }
}
