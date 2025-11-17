//
// Created by prag on 11/17/25.
//

#include "Meaning.h"

namespace scrptm {

    const std::string_view Meaning::getMeaning() const {
        return this->meaning;
    }

    const Language &Meaning::getLanguage() const {
        return this->language;
    }

} // scrptm