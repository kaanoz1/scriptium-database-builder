#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHRAWCHAPTEROFWORDFILE_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHRAWCHAPTEROFWORDFILE_H
#include <memory>

#include "../TorahRawVerseOfWordFile/TorahRawVerseOfWordFile.h"

namespace scrptm {
    class TorahRawChapterOfWordFile {
        const unsigned int index;
         std::vector<std::unique_ptr<TorahRawVerseOfWordFile>> verses;

    public:
        TorahRawChapterOfWordFile(unsigned int index, std::vector<std::unique_ptr< TorahRawVerseOfWordFile>> verses);

        [[nodiscard]] unsigned int getIndex() const;
        [[nodiscard]] const std::vector<std::unique_ptr< TorahRawVerseOfWordFile>>& getVerses() const;

        [[nodiscard]] std::unique_ptr<TorahRawVerseOfWordFile> giveVerseOfWordAtIndex(size_t verseIndex);
        [[nodiscard]] size_t getVerseCount() const;
    };
} // scrptm

#endif