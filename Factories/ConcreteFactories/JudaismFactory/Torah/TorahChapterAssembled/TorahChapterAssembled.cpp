#include "TorahChapterAssembled.h"

#include <algorithm>

namespace scrptm {
    TorahChapterAssembled::TorahChapterAssembled(const unsigned char index, std::string name,
                                                 std::vector<std::unique_ptr<TorahVerseAssembled> >
                                                 verses) : index(index), name(std::move(name)),
                                                           verses(std::move(verses)) {
    }

    unsigned char TorahChapterAssembled::getIndex() const {
        return this->index;
    }

    std::string TorahChapterAssembled::getName() const {
        return this->name;
    }


    const std::vector<std::unique_ptr<TorahVerseAssembled> > &TorahChapterAssembled::getVerses() const {
        return this->verses;
    }

    std::vector<std::unique_ptr<TorahVerseAssembled> > TorahChapterAssembled::giveVerses() {
        return std::move(this->verses);
    }
} // scrptm
