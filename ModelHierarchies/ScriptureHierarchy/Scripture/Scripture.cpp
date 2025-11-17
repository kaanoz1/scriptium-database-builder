
#include "Scripture.h"

namespace scrptm {
    Scripture::Scripture(const std::string_view name, const unsigned char code, const unsigned char number,
                         const std::pmr::vector<std::reference_wrapper<ScriptureMeaning> > &meanings,
                         const std::pmr::vector<std::reference_wrapper<Section> > &sections)
        : name(name),
          code(code),
          number(number),
          meanings(meanings),
          sections(sections) {
    }

    const unsigned char Scripture::getCode() const {
        return this->code;
    }

    const std::pmr::vector<std::reference_wrapper<ScriptureMeaning> > &Scripture::getMeanings() const {
        return this->meanings;
    }

    const std::string_view Scripture::getName() const {
        return this->name;
    }

    const unsigned char Scripture::getNumber() const {
        return this->number;
    }

    const std::pmr::vector<std::reference_wrapper<Section> > &Scripture::getSections() const {
        return this->sections;
    }




}
