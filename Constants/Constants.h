#ifndef SCRIPTIUM_DATABASE_BUILDER_CONSTANTS_H
#define SCRIPTIUM_DATABASE_BUILDER_CONSTANTS_H
#include "../ModelHierarchies/ScriptureHierarchy/Language/Language.h"

namespace constants {
    namespace General::Language {
        inline const scrptm::Language english{"English", "English", "en"};
        inline const scrptm::Language &englishRef{english};
    }

    namespace Judaism::Torah {
        inline constexpr unsigned char sectionCount = 39;
    }
}

#endif
