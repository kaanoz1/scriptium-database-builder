#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHSECTIONASSEMBLED_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHSECTIONASSEMBLED_H
#include <memory>
#include <string>
#include <vector>

#include "../TorahChapterAssembled/TorahChapterAssembled.h"

namespace scrptm {
    class TorahSectionAssembled {
        const unsigned char sectionNumber;
        const std::string sectionNameHebrew;
        const std::string sectionTitleInEnglish;

        std::vector<std::unique_ptr<TorahChapterAssembled> > chapters;

    public:
        TorahSectionAssembled(unsigned char sectionNumber, std::string sectionNameHebrew,
                              std::string sectionTitleInEnglish,
                              std::vector<std::unique_ptr<TorahChapterAssembled> > chapters);

        [[nodiscard]] unsigned char getSectionNumber() const;

        [[nodiscard]] std::string_view getSectionTitleHebrew() const;

        [[nodiscard]] std::string_view getSectionTitleInEnglish() const;

        [[nodiscard]] const std::vector<std::unique_ptr<TorahChapterAssembled> > &getChapters() const;

        [[nodiscard]] std::vector<std::unique_ptr<TorahChapterAssembled> > giveChapters();
    };
} // scrptm

#endif
