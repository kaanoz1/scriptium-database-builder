//
// Created by prag on 11/6/25.
//

#ifndef SCRIPTIUM_DATABASE_BUILDER_SCRIPTUREMEANING_H
#define SCRIPTIUM_DATABASE_BUILDER_SCRIPTUREMEANING_H
#include <string_view>
#include "../Language/Language.h"

class ScriptureMeaning {
private:
    const std::string_view meaning;
    const Language& language;

public:
    ScriptureMeaning(std::string_view meaning, const Language &language);

    [[nodiscard]] const std::string_view getMeaning() const;
    [[nodiscard]] const Language& getLanguage() const;
};


#endif //SCRIPTIUM_DATABASE_BUILDER_SCRIPTUREMEANING_H