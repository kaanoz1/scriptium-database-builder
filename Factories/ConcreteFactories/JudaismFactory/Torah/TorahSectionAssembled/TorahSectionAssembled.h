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

        std::vector<std::unique_ptr<const TorahChapterAssembled> > chapters;

    public:
        [[nodiscard]] unsigned char getSectionNumber() const;

        [[nodiscard]] const std::string_view getSectionTitleHebrew() const;

        [[nodiscard]] const std::string_view getSectionTitleInEnglish() const;

        [[nodiscard]] const std::vector<std::unique_ptr<const TorahChapterAssembled> > &getChapters() const;
    };
} // scrptm

#endif
