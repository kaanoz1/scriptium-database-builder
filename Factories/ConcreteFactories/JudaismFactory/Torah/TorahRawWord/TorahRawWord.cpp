#include "TorahRawWord.h"

#include <algorithm>
#include <iostream>
#include <ostream>
#include <stdexcept>

namespace scrptm {
    TorahRawWord::TorahRawWord(const std::string text, const std::string lemma,
                               const unsigned int index) : text(text), lemma(lemma), index(index) {
    }

    unsigned int TorahRawWord::getIndex() const {
        return this->index;
    }

    std::string_view TorahRawWord::getLemma() const {
        return this->lemma;
    }

    unsigned int TorahRawWord::getLemmaId() const {
        throw std::invalid_argument("Not implemented yet");
    }

    std::string_view TorahRawWord::getText() const {
        return this->text;
    }

    std::string TorahRawWord::giveText() {
        return std::move(this->text);
    }
}
