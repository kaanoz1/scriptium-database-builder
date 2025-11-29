#include "Verse.h"

#include <algorithm>

namespace scrptm {
    Verse::Verse(unsigned short number, std::string text, std::string text_simplified, std::string text_without_vowel,
                 std::vector<std::unique_ptr<Word> > &&words,
                 std::vector<std::unique_ptr<Transliteration> > &&transliterations) : number(number),
        text(std::move(text)),
        textSimplified(std::move(text_simplified)), textWithoutVowel(std::move(text_without_vowel)),
        words(std::move(words)), transliterations(std::move(transliterations)) {
    }


    const unsigned short Verse::getNumber() const {
        return this->number;
    }

    size_t Verse::getWordCount() const {
        return this->getWords().size();
    }


    const std::string Verse::getText() const {
        return this->text;
    }

    const std::string Verse::getTextSimplified() const {
        return this->textSimplified;
    }

    const std::string Verse::getTextWithoutVowel() const {
        return this->textWithoutVowel;
    }

    const std::vector<std::unique_ptr<Transliteration> > &Verse::getTransliterations() const {
        return this->transliterations;
    }

    const std::vector<std::unique_ptr<Word> > &Verse::getWords() const {
        return this->words;
    }
}
