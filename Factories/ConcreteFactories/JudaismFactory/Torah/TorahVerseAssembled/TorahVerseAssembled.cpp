#include "TorahVerseAssembled.h"

#include <algorithm>

namespace scrptm {
    TorahVerseAssembled::TorahVerseAssembled(unsigned int index, std::unique_ptr<const TorahRawVerse> usual,
                                             std::unique_ptr<const TorahRawVerse> simplified,
                                             std::unique_ptr<const TorahRawVerse> noVowel,
                                             std::vector<std::unique_ptr<const TorahRawWord> > words) : index(index),
        usual(std::move(usual)), simplified(std::move(simplified)), noVowel(std::move(noVowel)),
        words(std::move(words)) {
    }
} // scrptm
