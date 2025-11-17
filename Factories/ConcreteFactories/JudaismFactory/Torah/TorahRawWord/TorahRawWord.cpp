#include "TorahRawWord.h"

#include <stdexcept>

namespace scrptm {
    TorahRawWord::TorahRawWord(const std::string_view text, const std::string_view lemma,
                               const unsigned int index) : text(text), lemma(lemma), index(index) {
    }

    const unsigned int TorahRawWord::getIndex() const {
        return this->index;
    }

    const std::string_view TorahRawWord::getLemma() const {
        return this->lemma;
    }

    const unsigned short TorahRawWord::getLemmaId() const {
        //TODO: Implement
        throw std::invalid_argument("Not implemented yet");
    }

    const std::string_view TorahRawWord::getText() const {
        return this->text;
    }
}
