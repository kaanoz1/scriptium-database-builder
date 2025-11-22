#include "TorahRawChapter.h"

#include <algorithm>

namespace scrptm {
    TorahRawChapter::TorahRawChapter(unsigned char index,
                                     std::vector<std::unique_ptr<TorahRawVerse> > verses) : index(index),
        verses(std::move(verses)) {
    }

    unsigned char TorahRawChapter::getIndex() const {
        return this->index;
    }

    std::unique_ptr<TorahRawVerse> TorahRawChapter::giveVerseAtIndex(const size_t verseIndex) {
        return std::move(this->verses.at(verseIndex));
    }


    const std::vector<std::unique_ptr<TorahRawVerse> > &TorahRawChapter::getVerses() const {
        return this->verses;
    }


    size_t TorahRawChapter::getVerseCount() const {
        return this->getVerses().size();
    }
} // scrptm
