#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHVARIATIONFILE_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHVARIATIONFILE_H
#include <memory>
#include <string>
#include <vector>

#include "../TorahRawChapter/TorahRawChapter.h"

namespace scrptm {
    class TorahVariationFile {
        const std::string sectionNameHebrew;
        const std::string sectionTitleEnglish;

        const std::vector<std::unique_ptr<const TorahRawChapter>> chapters;

    public:
        TorahVariationFile(std::string sectionNameHebrew, std::string sectionTitleEnglish, std::vector<std::unique_ptr<const TorahRawChapter>> chapters);

        [[nodiscard]] std::string_view getTitle() const;
        [[nodiscard]] std::string_view getTitleEnglish() const;
        [[nodiscard]] const std::vector<std::unique_ptr<const TorahRawChapter>> &getChapters() const;

        [[nodiscard]] size_t getChaptersCount() const;
        [[nodiscard]] size_t getVerseCount() const;
    };
} // scrptm

#endif