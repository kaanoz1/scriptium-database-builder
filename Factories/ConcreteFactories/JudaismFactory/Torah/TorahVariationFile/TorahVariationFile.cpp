#include "TorahVariationFile.h"

namespace scrptm {
    TorahVariationFile::TorahVariationFile(std::string_view sectionNameHebrew, std::string_view sectionTitleEnglish,
                                           std::vector<std::unique_ptr<const TorahRawChapter> >
                                           chapters) : sectionNameHebrew(sectionNameHebrew),
                                                       sectionTitleEnglish(sectionTitleEnglish),
                                                       chapters(std::move(chapters)) {
    }


    std::string_view TorahVariationFile::getTitle() const {
        return this->sectionNameHebrew;
    }

    std::string_view TorahVariationFile::getTitleEnglish() const {
        return this->sectionTitleEnglish;
    }

    const std::vector<std::unique_ptr<const TorahRawChapter> > &TorahVariationFile::getChapters() const {
        return this->chapters;
    }

    size_t TorahVariationFile::getChaptersCount() const {
        return this->getChapters().size();
    }


    size_t TorahVariationFile::getVerseCount() const {
        size_t size = 0;

        for (const auto &chapter: this->getChapters())
            size += chapter->getVerseCount();

        return size;
    }
} // scrptm
