
#include "Chapter.h"

namespace scrptm {
    Chapter::Chapter(unsigned short number, std::string_view name,
                     const std::pmr::vector<std::reference_wrapper<Verse> > &verses,
                     const std::pmr::vector<std::reference_wrapper<ChapterMeaning> > &meanings) : number(number),
        name(name),
        verses(verses),
        meanings(meanings) {
    }


    const std::string_view scrptm::Chapter::getName() const {
        return this->name;
    }

    const unsigned short scrptm::Chapter::getNumber() const {
        return this->number;
    }

    const std::pmr::vector<std::reference_wrapper<Verse> > &scrptm::Chapter::getVerses() const {
        return this->verses;
    }

    const std::pmr::vector<std::reference_wrapper<ChapterMeaning> > &scrptm::Chapter::getMeanings() const {
        return this->meanings;
    }
}
