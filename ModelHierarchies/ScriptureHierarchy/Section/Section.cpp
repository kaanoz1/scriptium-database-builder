#include "Section.h"

#include <algorithm>

namespace scrptm {
    Section::Section(unsigned short number, const std::string name,
                     std::vector<std::unique_ptr<Chapter> > &&chapters,
                     std::vector<std::unique_ptr<SectionMeaning> > &&meanings) : number(number),
        name(std::move(name)), chapters(std::move(chapters)), meanings(std::move(meanings)) {
    }

    std::vector<std::unique_ptr<Chapter> > Section::giveChapters() {
        return std::move(this->chapters);
    }

    std::vector<std::unique_ptr<SectionMeaning> > Section::giveMeanings() {
        return std::move(this->meanings);
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
