#ifndef SCRIPTIUM_DATABASE_BUILDER_VERSEINDICATOR_H
#define SCRIPTIUM_DATABASE_BUILDER_VERSEINDICATOR_H
#include "../ChapterIndicator/ChapterIndicator.h"

namespace scrptm {
    class VerseIndicator {
        ChapterIndicator indicator;
        const unsigned short verseNumber;

    public:
        VerseIndicator(unsigned char scriptureCode, unsigned short sectionNumber, unsigned short chapterNumber,
                       unsigned short verseNumber);

        unsigned char getScriptureCode() const;

        unsigned short getSectionNumber() const;

        unsigned short getChapterNumber() const;

        unsigned short getVerseNumber() const;
    };
} // scrptm

#endif
