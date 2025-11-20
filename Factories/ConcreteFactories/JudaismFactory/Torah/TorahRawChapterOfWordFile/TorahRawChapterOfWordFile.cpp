#include "TorahRawChapterOfWordFile.h"

namespace scrptm {
    TorahRawChapterOfWordFile::TorahRawChapterOfWordFile(unsigned int index,
                                                         std::vector<std::unique_ptr<const TorahRawVerseOfWordFile> >
                                                         verses) : index(index), verses(std::move(verses)) {
    }

    unsigned int TorahRawChapterOfWordFile::getIndex() const {
        return this->index;
    }

    const std::vector<std::unique_ptr<const TorahRawVerseOfWordFile> > &TorahRawChapterOfWordFile::getVerses() const {
        return this->verses;
    }
} // scrptm
