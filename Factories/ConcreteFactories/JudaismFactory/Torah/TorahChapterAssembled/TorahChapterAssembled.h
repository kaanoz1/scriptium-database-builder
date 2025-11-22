#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHCHAPTERASSEMBLED_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHCHAPTERASSEMBLED_H
#include <memory>
#include <vector>

#include "../TorahVerseAssembled/TorahVerseAssembled.h"

namespace scrptm {
    class TorahChapterAssembled {
        const unsigned char index;
        std::vector<std::unique_ptr<TorahVerseAssembled> > verses;

    public:
        TorahChapterAssembled(unsigned char index, std::vector<std::unique_ptr<TorahVerseAssembled> > verses);

        [[nodiscard]] unsigned char getIndex() const;

        [[nodiscard]] const std::vector<std::unique_ptr<TorahVerseAssembled> > &getVerses() const;

        [[nodiscard]] std::vector<std::unique_ptr<TorahVerseAssembled> > giveVerses();
    };
} // scrptm

#endif
