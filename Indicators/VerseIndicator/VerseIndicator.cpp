#include "VerseIndicator.h"

namespace scrptm {
    VerseIndicator::VerseIndicator(unsigned char scriptureCode, unsigned short sectionNumber,
                                   unsigned short chapterNumber,
                                   unsigned short verseNumber) : indicator(scriptureCode, sectionNumber, chapterNumber),
                                                                 verseNumber(verseNumber) {
    }

    unsigned char VerseIndicator::getScriptureCode() const {
        return this->indicator.getScriptureCode();
    }

    unsigned short VerseIndicator::getSectionNumber() const {
        return this->indicator.getSectionNumber();
    }

    unsigned short VerseIndicator::getChapterNumber() const {
        return this->indicator.getChapterNumber();
    }

    unsigned short VerseIndicator::getVerseNumber() const {
        return this->verseNumber;
    }
} // scrptm
