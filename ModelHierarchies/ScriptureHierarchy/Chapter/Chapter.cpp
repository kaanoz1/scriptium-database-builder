#include "Chapter.h"

#include <algorithm>

namespace scrptm {
    Chapter::Chapter(unsigned short number, std::string name, std::vector<std::unique_ptr<Verse> > &&verses,
                     std::vector<std::unique_ptr<ChapterMeaning> > &&meanings) : number(number), name(std::move(name)),
        verses(std::move(verses)), meanings(std::move(meanings)) {
    }


    std::string scrptm::Chapter::getName() const {
        return this->name;
    }

    unsigned short scrptm::Chapter::getNumber() const {
        return this->number;
    }

    const std::vector<std::unique_ptr<Verse> > &Chapter::getVerses() const {
        return this->verses;
    }

    const std::vector<std::unique_ptr<ChapterMeaning> > &Chapter::getMeanings() const {
        return this->meanings;
    }

    size_t Chapter::getVerseCount() const {
        return this->getVerses().size();
    }
}
