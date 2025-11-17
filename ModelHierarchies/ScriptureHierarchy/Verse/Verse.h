
#ifndef SCRIPTIUM_DATABASE_BUILDER_VERSE_H
#define SCRIPTIUM_DATABASE_BUILDER_VERSE_H
#include <string_view>
#include <vector>

#include "../Word/Word.h"
#include "../Transliteration/Transliteration.h"

namespace scrptm {
    class Verse {
        const unsigned short number;
        const std::string_view text;
        const std::string_view textWithoutVowel;
        const std::string_view textSimplified;
        const std::pmr::vector<std::reference_wrapper<Word> > &words;
        const std::pmr::vector<std::reference_wrapper<Transliteration> > &transliterations;

    public:
        Verse(unsigned short number, std::string_view text, std::string_view text_without_vowel,
              std::string_view text_simplified, const std::pmr::vector<std::reference_wrapper<Word> > &words,
              const std::pmr::vector<std::reference_wrapper<Transliteration> > &transliterations);

        [[nodiscard]] const unsigned short getNumber() const;

        [[nodiscard]] const std::string_view getText() const;

        [[nodiscard]] const std::string_view getTextWithoutVowel() const;

        [[nodiscard]] const std::string_view getTextSimplified() const;

        [[nodiscard]] const std::pmr::vector<std::reference_wrapper<Word> > &getWords() const;

        [[nodiscard]] const std::pmr::vector<std::reference_wrapper<Transliteration> > &getTransliterations() const;
    };
}


#endif
