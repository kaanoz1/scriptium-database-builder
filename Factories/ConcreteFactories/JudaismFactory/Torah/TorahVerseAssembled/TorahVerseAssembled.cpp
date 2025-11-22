#include "TorahVerseAssembled.h"

#include <algorithm>

namespace scrptm {
    TorahVerseAssembled::TorahVerseAssembled(unsigned int index, std::unique_ptr<TorahRawVerse> usual,
                                             std::unique_ptr<TorahRawVerse> simplified,
                                             std::unique_ptr<TorahRawVerse> noVowel,
                                             std::vector<std::unique_ptr<TorahRawWord> > words) : index(index),
        usual(std::move(usual)), simplified(std::move(simplified)), noVowel(std::move(noVowel)),
        words(std::move(words)) {
    }

    unsigned int TorahVerseAssembled::getIndex() const {
        return this->index;
    }

    const TorahRawVerse &TorahVerseAssembled::getNoVowel() const {
        return *this->noVowel;
    }

    const TorahRawVerse &TorahVerseAssembled::getSimplified() const {
        return *this->simplified;
    }

    const TorahRawVerse &TorahVerseAssembled::getUsual() const {
        return *this->usual;
    }

    const std::vector<std::unique_ptr<TorahRawWord> > &TorahVerseAssembled::getWords() const {
        return this->words;
    }
} // scrptm
