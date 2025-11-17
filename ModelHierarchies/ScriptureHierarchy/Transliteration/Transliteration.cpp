
#include "Transliteration.h"

namespace scrptm {
    Transliteration::Transliteration(const std::string_view text, const Language &language) : text(text),
        language(language) {
    }
}
