
#ifndef SCRIPTIUM_DATABASE_BUILDER_TRANSLITERATION_H
#define SCRIPTIUM_DATABASE_BUILDER_TRANSLITERATION_H
#include <string_view>

#include "../Language/Language.h"

namespace scrptm {
    class Transliteration {
        const std::string_view text;
        const Language &language;

    public:
        Transliteration(std::string_view text, const Language &language);


        [[nodiscard]] const Language &getLanguage() const;

        [[nodiscard]] const std::string_view getText() const;
    };
}


#endif //SCRIPTIUM_DATABASE_BUILDER_TRANSLITERATION_H
