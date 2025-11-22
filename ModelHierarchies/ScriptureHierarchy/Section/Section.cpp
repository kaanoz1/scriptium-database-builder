#include "Section.h"

#include <algorithm>

namespace scrptm {
    Section::Section(unsigned short number, const std::string name,
                     std::vector<std::unique_ptr<Chapter> > &&chapters,
                     std::vector<std::unique_ptr<SectionMeaning> > &&meanings) : number(number),
        name(std::move(name)), chapters(std::move(chapters)), meanings(std::move(meanings)) {
    }

    std::string_view Section::getName() const {
        return this->name;
    }

    unsigned short Section::getNumber() const {
        return this->number;
    }

    const std::vector<std::unique_ptr<Chapter> > &Section::getChapters() const {
        return this->chapters;
    }

    size_t Section::getChapterCount() const {
        return this->getChapters().size();
    }

    size_t Section::getVerseCount() const {
        size_t sum = 0;

        for (const auto &chapter: this->getChapters())
            sum += chapter->getVerseCount();


        return sum;
    }


    const std::vector<std::unique_ptr<SectionMeaning> > &Section::getMeanings() const {
        return this->meanings;
    }
}
