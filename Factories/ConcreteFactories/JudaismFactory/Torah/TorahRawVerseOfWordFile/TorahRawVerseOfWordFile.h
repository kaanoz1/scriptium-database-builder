#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHRAWVERSEOFWORDFILE_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHRAWVERSEOFWORDFILE_H
#include <memory>
#include <vector>

#include "../TorahRawWord/TorahRawWord.h"

namespace scrptm {
    class TorahRawVerseOfWordFile {
        const unsigned int index;
        const std::vector<std::unique_ptr<const TorahRawWord> > words;

    public:
        TorahRawVerseOfWordFile(unsigned int index, std::vector<std::unique_ptr<const TorahRawWord> > words);

        unsigned int getIndex() const;

        const std::vector<std::unique_ptr<const TorahRawWord> > &getWords() const;
    };
}

#endif
