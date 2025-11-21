#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHRAWCHAPTER_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHRAWCHAPTER_H
#include <memory>
#include <vector>

#include "../TorahRawVerse/TorahRawVerse.h"

namespace scrptm {
    class TorahRawChapter {
        const unsigned char index;
        const std::vector<std::unique_ptr<const TorahRawVerse> > verses;

    public:
        TorahRawChapter(unsigned char index, std::vector<std::unique_ptr<const TorahRawVerse> > verses);

        [[nodiscard]] unsigned char getIndex() const;

        [[nodiscard]] const std::vector<std::unique_ptr<const TorahRawVerse> > &getVerses() const;

        [[nodiscard]] size_t getVerseCount() const;
    };
} // scrptm

#endif
