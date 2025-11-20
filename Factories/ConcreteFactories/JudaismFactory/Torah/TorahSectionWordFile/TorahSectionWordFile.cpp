#include "TorahSectionWordFile.h"

namespace scrptm {
    TorahSectionWordFile::TorahSectionWordFile(
        std::vector<std::unique_ptr<const TorahRawChapterOfWordFile> > chapters) : chapters(std::move(chapters)) {
    }

    const std::vector<std::unique_ptr<const TorahRawChapterOfWordFile> > &TorahSectionWordFile::getChapters() const {
        return this->chapters;
    }
} // scrptm
