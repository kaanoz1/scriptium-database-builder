#include "TorahRawVerseOfWordFile.h"

namespace scrptm {
    TorahRawVerseOfWordFile::TorahRawVerseOfWordFile(const unsigned int index,
                                                     std::vector<std::unique_ptr<const TorahRawWord> > words) : index(
            index), words(std::move(words)) {
    }

    unsigned int TorahRawVerseOfWordFile::getIndex() const {
        return this->index;
    }

    const std::vector<std::unique_ptr<const TorahRawWord> > &TorahRawVerseOfWordFile::getWords() const {
        return this->words;
    }
}
