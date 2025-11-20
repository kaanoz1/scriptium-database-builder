#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHRAWCHAPTEROFWORDFILE_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHRAWCHAPTEROFWORDFILE_H
#include <memory>

#include "../TorahRawVerseOfWordFile/TorahRawVerseOfWordFile.h"

namespace scrptm {
    class TorahRawChapterOfWordFile {
        const unsigned int index;
        const std::vector<std::unique_ptr<const TorahRawVerseOfWordFile>> verses;

    public:
        TorahRawChapterOfWordFile(unsigned int index, std::vector<std::unique_ptr<const TorahRawVerseOfWordFile>> verses);

        [[nodiscard]] unsigned int getIndex() const;
        [[nodiscard]] const std::vector<std::unique_ptr<const TorahRawVerseOfWordFile>>& getVerses() const;
    };
} // scrptm

#endif