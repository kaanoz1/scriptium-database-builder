//
// Created by prag on 11/6/25.
//

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
}
