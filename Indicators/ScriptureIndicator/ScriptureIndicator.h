#ifndef SCRIPTIUM_DATABASE_BUILDER_SCRIPTUREINDICATOR_H
#define SCRIPTIUM_DATABASE_BUILDER_SCRIPTUREINDICATOR_H
#include <string>

namespace scrptm {
    class ScriptureIndicator {
        const unsigned char scriptureCode;

    public:
        explicit ScriptureIndicator(unsigned char scriptureCode);

        unsigned char getScriptureCode() const;
    };
} // scrptm

#endif
