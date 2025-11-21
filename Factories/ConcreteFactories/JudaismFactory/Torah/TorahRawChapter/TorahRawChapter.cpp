#include "TorahRawChapter.h"

namespace scrptm {
    TorahRawChapter::TorahRawChapter(unsigned char index,
                                     std::vector<std::unique_ptr<const TorahRawVerse> > verses) : index(index),
        verses(std::move(verses)) {
    }

    unsigned char TorahRawChapter::getIndex() const {
        return this->index;
    }


    const std::vector<std::unique_ptr<const TorahRawVerse> > &TorahRawChapter::getVerses() const {
        return this->verses;
    }
} // scrptm
