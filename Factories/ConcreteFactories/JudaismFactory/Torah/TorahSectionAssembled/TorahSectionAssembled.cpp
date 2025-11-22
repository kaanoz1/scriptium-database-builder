#include "TorahSectionAssembled.h"

#include <algorithm>

namespace scrptm {
    TorahSectionAssembled::TorahSectionAssembled(const unsigned char sectionNumber, std::string sectionNameHebrew,
                                                 std::string sectionTitleInEnglish,
                                                 std::vector<std::unique_ptr<TorahChapterAssembled> >
                                                 chapters) : sectionNumber(
                                                                 sectionNumber),
                                                             sectionNameHebrew(std::move(sectionNameHebrew)),
                                                             sectionTitleInEnglish(std::move(sectionTitleInEnglish)),
                                                             chapters(std::move(chapters)) {
    }

    const std::vector<std::unique_ptr<TorahChapterAssembled> > &TorahSectionAssembled::getChapters() const {
        return this->chapters;
    }

    std::vector<std::unique_ptr<TorahChapterAssembled> > TorahSectionAssembled::giveChapters() {
        return std::move(this->chapters);
    }


    unsigned char TorahSectionAssembled::getSectionNumber() const {
        return this->sectionNumber;
    }


    std::string_view TorahSectionAssembled::getSectionTitleHebrew() const {
        return this->sectionNameHebrew;
    }

    std::string_view TorahSectionAssembled::getSectionTitleInEnglish() const {
        return this->sectionTitleInEnglish;
    }
} // scrptm
