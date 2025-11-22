#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHVERSEASSEMBLED_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHVERSEASSEMBLED_H
#include <memory>
#include <vector>

#include "../TorahRawVerse/TorahRawVerse.h"
#include "../TorahRawWord/TorahRawWord.h"

namespace scrptm {
    class TorahVerseAssembled {
        const unsigned int index;
        std::unique_ptr<TorahRawVerse> usual;
        std::unique_ptr<TorahRawVerse> simplified;
        std::unique_ptr<TorahRawVerse> noVowel;
        std::vector<std::unique_ptr<TorahRawWord> > words;

    public:
        TorahVerseAssembled(unsigned int index, std::unique_ptr<TorahRawVerse> usual,
                            std::unique_ptr<TorahRawVerse> simplified,
                            std::unique_ptr<TorahRawVerse> noVowel,
                            std::vector<std::unique_ptr<TorahRawWord> > words);

        [[nodiscard]] unsigned int getIndex() const;

        [[nodiscard]] const TorahRawVerse &getUsual() const;

        [[nodiscard]] const TorahRawVerse &getSimplified() const;

        [[nodiscard]] const TorahRawVerse &getNoVowel() const;

        [[nodiscard]] const std::vector<std::unique_ptr<TorahRawWord> > &getWords() const;

        [[nodiscard]] std::unique_ptr<TorahRawVerse> giveUsual();

        [[nodiscard]] std::unique_ptr<TorahRawVerse> giveSimplified();

        [[nodiscard]] std::unique_ptr<TorahRawVerse> giveNoVowel();

        [[nodiscard]] std::vector<std::unique_ptr<TorahRawWord> > giveWords();
    };
} // scrptm

#endif
