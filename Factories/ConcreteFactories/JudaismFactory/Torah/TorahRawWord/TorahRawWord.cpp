#include "TorahRawWord.h"

#include <iostream>
#include <ostream>
#include <stdexcept>

namespace scrptm {
    TorahRawWord::TorahRawWord(const std::string_view text, const std::string_view lemma,
                               const unsigned int index) : text(text), lemma(lemma), index(index) {
    }

    unsigned int TorahRawWord::getIndex() const {
        return this->index;
    }

    std::string_view TorahRawWord::getLemma() const {
        return this->lemma;
    }

    unsigned short TorahRawWord::getLemmaId() const {
        throw std::invalid_argument("Not implemented yet");
    }

    std::string_view TorahRawWord::getText() const {
        return this->text;
    }
}
