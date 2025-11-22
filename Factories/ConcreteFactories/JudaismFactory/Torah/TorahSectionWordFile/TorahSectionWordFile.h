#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHSECTIONWORDFILE_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHSECTIONWORDFILE_H
#include <memory>
#include <vector>

#include "../TorahRawChapterOfWordFile/TorahRawChapterOfWordFile.h"

namespace scrptm {
    class TorahSectionWordFile {
        std::vector<std::unique_ptr<TorahRawChapterOfWordFile> > chapters;

    public:
        explicit TorahSectionWordFile(std::vector<std::unique_ptr< TorahRawChapterOfWordFile> > chapters);

        [[nodiscard]] const std::vector<std::unique_ptr< TorahRawChapterOfWordFile> > &getChapters() const;

        [[nodiscard]] std::unique_ptr<TorahRawChapterOfWordFile> giveChapterAtIndex(size_t index);

        [[nodiscard]] size_t getChapterCount() const;

        [[nodiscard]] size_t getVerseCountAtChapter(size_t chapterIndex) const;

        [[nodiscard]] size_t getVerseCount() const;
    };
} // scrptm

#endif
