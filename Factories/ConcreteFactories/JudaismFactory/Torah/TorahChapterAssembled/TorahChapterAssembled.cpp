#include "TorahChapterAssembled.h"

namespace scrptm {
    TorahChapterAssembled::TorahChapterAssembled(const unsigned char index,
                                                 std::vector<std::unique_ptr<TorahVerseAssembled> >
                                                 verses) : index(index), verses(std::move(verses)) {
    }

    unsigned char TorahChapterAssembled::getIndex() const {
        return this->index;
    }


    const std::vector<std::unique_ptr<TorahVerseAssembled> > &TorahChapterAssembled::getVerses() const {
        return this->verses;
    }

    std::vector<std::unique_ptr<TorahVerseAssembled> > TorahChapterAssembled::giveVerses() {
        return std::move(this->verses);
    }

} // scrptm
