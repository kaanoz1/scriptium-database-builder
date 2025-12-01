#ifndef SCRIPTIUM_DATABASE_BUILDER_SCRIPTUREINDICATOR_H
#define SCRIPTIUM_DATABASE_BUILDER_SCRIPTUREINDICATOR_H
#include <string>

namespace scrptm {
    class ScriptureIndicator {
        const char scriptureCode;

    public:
        explicit ScriptureIndicator(char scriptureCode);

        char getScriptureCode() const;

    };
} // scrptm

#endif