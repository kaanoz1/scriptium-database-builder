#include "TranslationText.h"

namespace scrptm {
    TranslationText::TranslationText(std::string &&content, std::vector<Footnote> &&footnotes,
                                     VerseIndicator &&verseIndicator) : content(std::move(content)),
                                                                        footnotes(std::move(footnotes)),
                                                                        verseIndicator(std::move(verseIndicator)) {
    }

    std::string TranslationText::copyContent() const {
        return this->content;
    }

    const std::vector<Footnote> &TranslationText::getFootnotes() const {
        return this->footnotes;
    }

    const VerseIndicator &TranslationText::getVerseIndicator() const {
        return this->verseIndicator;
    }
} // scrptm
