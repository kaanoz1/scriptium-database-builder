#ifndef SCRIPTIUM_DATABASE_BUILDER_SECTIONINDICATOR_H
#define SCRIPTIUM_DATABASE_BUILDER_SECTIONINDICATOR_H
#include "../ScriptureIndicator/ScriptureIndicator.h"

namespace scrptm {
    class SectionIndicator {
        ScriptureIndicator scriptureIndicator;
        const unsigned short sectionNumber;

    public:
        SectionIndicator(unsigned char scriptureCode, unsigned short sectionNumber);

        unsigned char getScriptureCode() const;

        unsigned short getSectionNumber() const;
    };
} // scrptm

#endif
