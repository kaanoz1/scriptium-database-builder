#include "SectionIndicator.h"

namespace scrptm {
    SectionIndicator::SectionIndicator(const unsigned char scriptureCode,
                                       const unsigned short sectionNumber) : scriptureIndicator(
                                                                                 scriptureCode),

                                                                             sectionNumber(sectionNumber) {
    }

    unsigned char SectionIndicator::getScriptureCode() const {
        return this->scriptureIndicator.getScriptureCode();
    }

    unsigned short SectionIndicator::getSectionNumber() const {
        return this->sectionNumber;
    }
} // scrptm
