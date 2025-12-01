#include "Footnote.h"
#include "../Footnote.h"

#include <string>

namespace scrptm {
    Footnote::Footnote(std::string indicator, const unsigned long long index,
                       std::string content) : indicator(indicator),
                                              index(index), content(content) {
    }

    std::string Footnote::copyContent() const {
        return this->content;
    }

    std::string Footnote::copyIndicator() const {
        return this->indicator;
    }

    const std::string &Footnote::getContent() const {
        return this->content;
    }

    unsigned long long Footnote::getIndex() const {
        return this->index;
    }

    const std::string &Footnote::getIndicator() const {
        return this->indicator;
    }
} // scrptm
