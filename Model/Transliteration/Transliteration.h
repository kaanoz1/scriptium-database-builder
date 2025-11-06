//
// Created by prag on 11/6/25.
//

#ifndef SCRIPTIUM_DATABASE_BUILDER_TRANSLITERATION_H
#define SCRIPTIUM_DATABASE_BUILDER_TRANSLITERATION_H
#include <string_view>

#include "../Language/Language.h"


class Transliteration {
    const std::string_view text;
    const Language& language;



public:
    Transliteration(const std::string_view text, const Language &language)
        : text(text),
          language(language) {
    }


    [[nodiscard]] const Language& getLanguage() const;
    [[nodiscard]] const std::string_view getText() const;
};



#endif //SCRIPTIUM_DATABASE_BUILDER_TRANSLITERATION_H