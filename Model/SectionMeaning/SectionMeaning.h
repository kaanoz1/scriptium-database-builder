//
// Created by prag on 11/6/25.
//

#ifndef SCRIPTIUM_DATABASE_BUILDER_SECTIONMEANING_H
#define SCRIPTIUM_DATABASE_BUILDER_SECTIONMEANING_H
#include <string_view>
#include "../Language/Language.h"

class SectionMeaning {
private:
    const std::string_view meaning;
    const Language& language;

public:
    SectionMeaning(const std::string_view meaning, const Language &language)
        : meaning(meaning),
          language(language) {
    }

    [[nodiscard]] const std::string_view getMeaning() const;
    [[nodiscard]] const Language& getLanguage() const;
};


#endif //SCRIPTIUM_DATABASE_BUILDER_SECTIONMEANING_H