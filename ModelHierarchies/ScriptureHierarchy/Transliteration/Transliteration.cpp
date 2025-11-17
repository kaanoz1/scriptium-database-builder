//
// Created by prag on 11/6/25.
//

#include "Transliteration.h"

namespace scrptm {
    Transliteration::Transliteration(const std::string_view text, const Language &language) : text(text),
        language(language) {
    }
}
