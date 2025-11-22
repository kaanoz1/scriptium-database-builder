#include "Scripture.h"

#include <algorithm>
#include <memory>

namespace scrptm {
    Scripture::Scripture(std::string &&name, const unsigned char code, const unsigned char number,
                         std::vector<std::unique_ptr<ScriptureMeaning> >&& meanings,
                         std::vector<std::unique_ptr<Section> >&& sections)
        : name(name),
          code(code),
          number(number),
          meanings(std::move(meanings)),
          sections(std::move(sections)) {
    }

    unsigned char Scripture::getCode() const {
        return this->code;
    }

    const std::vector<std::unique_ptr<ScriptureMeaning> > &Scripture::getMeanings() const {
        return this->meanings;
    }

    std::string_view Scripture::getName() const {
        return this->name;
    }

    unsigned char Scripture::getNumber() const {
        return this->number;
    }

    const std::vector<std::unique_ptr<Section> > &Scripture::getSections() const {
        return this->sections;
    }
}
