#include "TorahVariationFile.h"

#include <algorithm>
#include <utility>

namespace scrptm {
    TorahVariationFile::TorahVariationFile(std::string sectionNameHebrew, std::string sectionTitleEnglish,
                                           std::vector<std::unique_ptr<TorahRawChapter> >
                                           chapters) : sectionNameHebrew(std::move(sectionNameHebrew)),
                                                       sectionTitleEnglish(std::move(sectionTitleEnglish)),
                                                       chapters(std::move(chapters)) {
    }


    std::string_view TorahVariationFile::getTitle() const {
        return this->sectionNameHebrew;
    }

    std::string_view TorahVariationFile::getTitleEnglish() const {
        return this->sectionTitleEnglish;
    }

    std::string TorahVariationFile::giveTitle() {
        return std::move(this->sectionNameHebrew);
    }

    std::string TorahVariationFile::giveTitleEnglish() {
        return std::move(this->sectionTitleEnglish);
    }

    const std::vector<std::unique_ptr<TorahRawChapter> > &TorahVariationFile::getChapters() const {
        return this->chapters;
    }

    std::unique_ptr<TorahRawChapter> TorahVariationFile::giveChapterAtIndex(const size_t index) {

        return std::move(this->chapters.at(index));
    }


    size_t TorahVariationFile::getChaptersCount() const {
        return this->getChapters().size();
    }

    size_t TorahVariationFile::getVerseCountAtChapter(size_t chapterIndex) const {
        return this->getChapters().at(chapterIndex)->getVerseCount();
    }


    size_t TorahVariationFile::getVerseCount() const {
        size_t size = 0;

        for (const auto &chapter: this->getChapters())
            size += chapter->getVerseCount();

        return size;
    }
} // scrptm
