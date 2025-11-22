#include "TorahRawVerseOfWordFile.h"

#include <algorithm>

namespace scrptm {
    TorahRawVerseOfWordFile::TorahRawVerseOfWordFile(const unsigned int index,
                                                     std::vector<std::unique_ptr<TorahRawWord> > words) : index(
            index), words(std::move(words)) {
    }

    unsigned int TorahRawVerseOfWordFile::getIndex() const {
        return this->index;
    }


    const std::vector<std::unique_ptr<TorahRawWord> > &TorahRawVerseOfWordFile::getWords() const {
        return this->words;
    }

    std::vector<std::unique_ptr<TorahRawWord> > TorahRawVerseOfWordFile::giveWords() {
        return std::move(this->words);
    }
}
