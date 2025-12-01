#include "ChapterIndicator.h"


namespace scrptm {
    ChapterIndicator::ChapterIndicator(unsigned char scriptureCode, unsigned short sectionNumber,
                                       unsigned short chapterNumber) : indicator(scriptureCode, sectionNumber),
                                                                       chapterNumber(chapterNumber) {
    }

    unsigned char ChapterIndicator::getScriptureCode() const {
        return this->indicator.getScriptureCode();
    }

    unsigned short ChapterIndicator::getSectionNumber() const {
        return this->indicator.getSectionNumber();
    }

    unsigned short ChapterIndicator::getChapterNumber() const {
        return this->chapterNumber;
    }
} // scrptm
