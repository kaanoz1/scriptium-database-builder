//
// Created by prag on 11/6/25.
//

#include "Verse.h"

namespace scrptm {
    Verse::Verse(unsigned short number, std::string_view text, std::string_view text_without_vowel,
                 std::string_view text_simplified, const std::pmr::vector<std::reference_wrapper<Word> > &words,
                 const std::pmr::vector<std::reference_wrapper<Transliteration> > &transliterations)
        : number(number),
          text(text),
          textWithoutVowel(text_without_vowel),
          textSimplified(text_simplified),
          words(words),
          transliterations(transliterations) {
    }


    const unsigned short Verse::getNumber() const {
        return this->number;
    }


    const std::string_view Verse::getText() const {
        return this->text;
    }

    const std::string_view Verse::getTextSimplified() const {
        return this->textSimplified;
    }

    const std::string_view Verse::getTextWithoutVowel() const {
        return this->textWithoutVowel;
    }

    const std::pmr::vector<std::reference_wrapper<Transliteration> > &Verse::getTransliterations() const {
        return this->transliterations;
    }

    const std::pmr::vector<std::reference_wrapper<Word> > &Verse::getWords() const {
        return this->words;
    }
}
