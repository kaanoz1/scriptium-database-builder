
#include "Meaning.h"

namespace scrptm {
    Meaning::Meaning(std::string_view meaning, const Language &language) : meaning(meaning), language(language) {
    }


    const std::string_view Meaning::getMeaning() const {
        return this->meaning;
    }

    const Language &Meaning::getLanguage() const {
        return this->language;
    }
}
