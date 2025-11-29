#include "Scripture.h"

#include <algorithm>
#include <memory>

namespace scrptm {
    Scripture::Scripture(std::string &&name, const char code, const  int number,
                         std::vector<std::unique_ptr<ScriptureMeaning> >&& meanings,
                         std::vector<std::unique_ptr<Section> >&& sections)
        : name(name),
          code(code),
          number(number),
          meanings(std::move(meanings)),
          sections(std::move(sections)) {
    }

    char Scripture::getCode() const {
        return this->code;
    }

    const std::vector<std::unique_ptr<ScriptureMeaning> > &Scripture::getMeanings() const {
        return this->meanings;
    }

    std::string Scripture::getName() const {
        return this->name;
    }

    int Scripture::getNumber() const {
        return this->number;
    }

    const std::vector<std::unique_ptr<Section> > &Scripture::getSections() const {
        return this->sections;
    }
}
