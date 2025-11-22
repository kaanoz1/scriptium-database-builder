#include "TorahRawVerse.h"

#include <utility>

namespace scrptm {
    TorahRawVerse::TorahRawVerse(unsigned short index, std::string text) : index(index), text(std::move(text)) {
    }

    unsigned short TorahRawVerse::getIndex() const {
        return this->index;
    }


    std::string_view TorahRawVerse::getText() const {
        return this->text;
    }
} // scrptm
