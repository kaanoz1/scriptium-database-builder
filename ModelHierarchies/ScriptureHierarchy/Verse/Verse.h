#ifndef SCRIPTIUM_DATABASE_BUILDER_VERSE_H
#define SCRIPTIUM_DATABASE_BUILDER_VERSE_H
#include <string_view>
#include <vector>

#include "../Word/Word.h"
#include "../Transliteration/Transliteration.h"

namespace scrptm {
    class Verse {
        const unsigned short number;
        const std::string text;
        const std::string textSimplified;
        const std::string textWithoutVowel;
        std::vector<std::unique_ptr<Word> > &&words;
        std::vector<std::unique_ptr<Transliteration> > &&transliterations;

    public:
        Verse(unsigned short number, std::string text,
              std::string text_simplified, std::string text_without_vowel,
              std::vector<std::unique_ptr<Word> > &&words,
              std::vector<std::unique_ptr<Transliteration> > &&transliterations);

        [[nodiscard]] const unsigned short getNumber() const;

        [[nodiscard]] const std::string_view getText() const;

        [[nodiscard]] const std::string_view getTextWithoutVowel() const;

        [[nodiscard]] const std::string_view getTextSimplified() const;

        [[nodiscard]] const std::vector<std::unique_ptr<Word> > &getWords() const;

        [[nodiscard]] size_t getWordCount() const;

        [[nodiscard]] const std::vector<std::unique_ptr<Transliteration> > &getTransliterations() const;
    };
}


#endif
