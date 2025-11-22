#include "TorahSectionWordFile.h"

#include <algorithm>

namespace scrptm {
    TorahSectionWordFile::TorahSectionWordFile(
        std::vector<std::unique_ptr<TorahRawChapterOfWordFile> > chapters) : chapters(std::move(chapters)) {
    }

    const std::vector<std::unique_ptr<TorahRawChapterOfWordFile> > &TorahSectionWordFile::getChapters() const {
        return this->chapters;
    }

    std::unique_ptr<TorahRawChapterOfWordFile> TorahSectionWordFile::giveChapterAtIndex(size_t index) {
        return std::move(this->chapters.at(index));
    }

    size_t TorahSectionWordFile::getChapterCount() const {
        return this->getChapters().size();
    }

    size_t TorahSectionWordFile::getVerseCountAtChapter(size_t chapterIndex) const {
        return this->getChapters().at(chapterIndex)->getVerseCount();
    }


    size_t TorahSectionWordFile::getVerseCount() const {
        size_t sum = 0;
        for (const auto &chapter: this->getChapters())
            sum += chapter->getVerseCount();

        return sum;
    }
} // scrptm
