
#ifndef SCRIPTIUM_DATABASE_BUILDER_MEANING_H
#define SCRIPTIUM_DATABASE_BUILDER_MEANING_H
#include <string_view>
#include "../Language/Language.h"

namespace scrptm {
    class Meaning {
        const std::string_view meaning;
        const Language& language;

    public:
        Meaning(std::string_view meaning, const Language &language);

        [[nodiscard]] const std::string_view getMeaning() const;
        [[nodiscard]] const Language& getLanguage() const;
    };
}

#endif