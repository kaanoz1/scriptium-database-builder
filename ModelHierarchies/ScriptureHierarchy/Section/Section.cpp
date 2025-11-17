
#include "Section.h"

namespace scrptm {
    Section::Section(unsigned short number, const std::string_view name,
                     const std::pmr::vector<std::reference_wrapper<Chapter> > &chapters,
                     const std::pmr::vector<std::reference_wrapper<SectionMeaning> > &meanings) : number(number),
        name(name),
        chapters(chapters),
        meanings(meanings) {
    }


    const std::string_view Section::getName() const {
        return this->name;
    }

    const unsigned short Section::getNumber() const {
        return this->number;
    }

    const std::pmr::vector<std::reference_wrapper<Chapter> > &Section::getChapters() const {
        return this->chapters;
    }

    const std::pmr::vector<std::reference_wrapper<SectionMeaning> > &Section::getMeanings() const {
        return this->meanings;
    }
}
