#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHVARIATIONFILE_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHVARIATIONFILE_H
#include <memory>
#include <string>
#include <vector>

#include "../TorahRawChapter/TorahRawChapter.h"

namespace scrptm {
    class TorahVariationFile {
        std::string sectionNameHebrew;
        std::string sectionTitleEnglish;
        std::vector<std::unique_ptr<TorahRawChapter>> chapters;

    public:
        TorahVariationFile(std::string sectionNameHebrew, std::string sectionTitleEnglish, std::vector<std::unique_ptr<TorahRawChapter>> chapters);

        [[nodiscard]] std::string_view getTitle() const;
        [[nodiscard]] std::string_view getTitleEnglish() const;

        [[nodiscard]] std::string giveTitle();
        [[nodiscard]] std::string giveTitleEnglish();

        [[nodiscard]] const std::vector<std::unique_ptr<TorahRawChapter>> &getChapters() const;

        [[nodiscard]] std::unique_ptr<TorahRawChapter> giveChapterAtIndex(size_t index);

        [[nodiscard]] size_t getChaptersCount() const;
        [[nodiscard]] size_t getVerseCountAtChapter(size_t chapterIndex) const;
        [[nodiscard]] size_t getVerseCount() const;
    };
} // scrptm

#endif