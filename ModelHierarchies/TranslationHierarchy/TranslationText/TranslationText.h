#ifndef SCRIPTIUM_DATABASE_BUILDER_TRANSLATIONTEXT_H
#define SCRIPTIUM_DATABASE_BUILDER_TRANSLATIONTEXT_H
#include <string>
#include <vector>

#include "../../../Indicators/VerseIndicator/VerseIndicator.h"
#include "../Footnote/Footnote.h"

namespace scrptm {
    class TranslationText {
        std::string content;
        std::vector<Footnote> footnotes;
        VerseIndicator verseIndicator;

    public:
        TranslationText(std::string&& content, std::vector<Footnote>&& footnotes, VerseIndicator&& verseIndicator);


        std::string copyContent() const;

        const VerseIndicator &getVerseIndicator() const;

        const std::vector<Footnote> &getFootnotes() const;
    };
} // scrptm

#endif
