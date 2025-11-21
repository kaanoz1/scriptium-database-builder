#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHVERSEASSEMBLED_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHVERSEASSEMBLED_H
#include <memory>
#include <vector>

#include "../TorahRawVerse/TorahRawVerse.h"
#include "../TorahRawWord/TorahRawWord.h"

namespace scrptm {
    class TorahVerseAssembled {
        const unsigned int index;
        const std::unique_ptr<const TorahRawVerse> usual;
        const std::unique_ptr<const TorahRawVerse> simplified;
        const std::unique_ptr<const TorahRawVerse> noVowel;
        std::vector<std::unique_ptr<const TorahRawWord> > words;

    public:
        TorahVerseAssembled(unsigned int index, std::unique_ptr<const TorahRawVerse> usual,
                            std::unique_ptr<const TorahRawVerse> simplified,
                            std::unique_ptr<const TorahRawVerse> noVowel,
                            std::vector<std::unique_ptr<const TorahRawWord> > words);

        [[nodiscard]] unsigned int getIndex() const;

        [[nodiscard]] const TorahRawVerse &getUsual() const;

        [[nodiscard]] const TorahRawVerse &getSimplified() const;

        [[nodiscard]] const TorahRawVerse &getNoVowel() const;

        [[nodiscard]] const std::vector<std::unique_ptr<const TorahRawWord> > &getWords() const;
    };
} // scrptm

#endif
