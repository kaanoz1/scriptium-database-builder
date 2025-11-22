#include "TorahRawChapterOfWordFile.h"

#include <algorithm>

namespace scrptm {
    TorahRawChapterOfWordFile::TorahRawChapterOfWordFile(unsigned int index,
                                                         std::vector<std::unique_ptr<TorahRawVerseOfWordFile> >
                                                         verses) : index(index), verses(std::move(verses)) {
    }

    unsigned int TorahRawChapterOfWordFile::getIndex() const {
        return this->index;
    }

    const std::vector<std::unique_ptr<TorahRawVerseOfWordFile> > &TorahRawChapterOfWordFile::getVerses() const {
        return this->verses;
    }

    std::unique_ptr<TorahRawVerseOfWordFile> TorahRawChapterOfWordFile::giveVerseOfWordAtIndex(size_t verseIndex) {
        return std::move(this->verses.at(verseIndex));
    }


    size_t TorahRawChapterOfWordFile::getVerseCount() const {
        return this->getVerses().size();
    }
} // scrptm
