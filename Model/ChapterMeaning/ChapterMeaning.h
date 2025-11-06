//
// Created by prag on 11/6/25.
//

#ifndef SCRIPTIUM_DATABASE_BUILDER_CHAPTERMEANING_H
#define SCRIPTIUM_DATABASE_BUILDER_CHAPTERMEANING_H
#include <string_view>

#include "../Chapter/Chapter.h"
#include "../Language/Language.h"


class ChapterMeaning {
private:
    const std::string_view meaning;
    const Language& language;

public:
    ChapterMeaning(const std::string_view meaning, const Language &language)
        : meaning(meaning),
          language(language) {
    }

    [[nodiscard]] const std::string_view getMeaning() const;
    [[nodiscard]] const Language& getLanguage() const;
};


#endif //SCRIPTIUM_DATABASE_BUILDER_CHAPTERMEANING_H