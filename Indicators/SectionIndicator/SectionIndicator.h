#ifndef SCRIPTIUM_DATABASE_BUILDER_SECTIONINDICATOR_H
#define SCRIPTIUM_DATABASE_BUILDER_SECTIONINDICATOR_H
#include "../ScriptureIndicator/ScriptureIndicator.h"

namespace scrptm {
    class SectionIndicator {
        ScriptureIndicator scriptureIndicator;
        const unsigned short  sectionNumber;

    public:
        SectionIndicator(char scriptureCode, unsigned short sectionNumber);

        char getScriptureCode() const;
        unsigned short getSectionNumber() const;
    };
} // scrptm

#endif