#ifndef SCRIPTIUM_DATABASE_BUILDER_CHAPTERINDICATOR_H
#define SCRIPTIUM_DATABASE_BUILDER_CHAPTERINDICATOR_H
#include "../SectionIndicator/SectionIndicator.h"

namespace scrptm {
    class ChapterIndicator {
        SectionIndicator indicator;
        const unsigned short chapterNumber;

    public:
        ChapterIndicator(unsigned char scriptureCode, unsigned short sectionNumber, unsigned short chapterNumber);

        unsigned char getScriptureCode() const;
        unsigned short getSectionNumber() const;
        unsigned short getChapterNumber() const;
    };
} // scrptm

#endif