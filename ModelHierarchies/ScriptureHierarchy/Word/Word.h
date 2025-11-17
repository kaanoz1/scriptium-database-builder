//
// Created by prag on 11/6/25.
//

#ifndef SCRIPTIUM_DATABASE_BUILDER_WORD_H
#define SCRIPTIUM_DATABASE_BUILDER_WORD_H
#include <string_view>
#include <vector>
#include "../Root/Root.h"

namespace scrptm {
    class Word {
    private:
        const unsigned int sequence_number;
        const std::string_view text;
        const std::string_view textWithoutVowel;
        const std::string_view textSimplified;
        const std::pmr::vector<std::reference_wrapper<Root> > &roots;

    public:
        Word(unsigned int sequence_number, std::string_view text, std::string_view text_without_vowel,
             std::string_view text_simplified, const std::pmr::vector<std::reference_wrapper<Root> > &roots);

        [[nodiscard]] const unsigned int getSequenceNumber() const;

        [[nodiscard]] const std::string_view getText() const;

        [[nodiscard]] const std::string_view getTextWithoutVowel() const;

        [[nodiscard]] const std::string_view getTextSimplified() const;

        [[nodiscard]] const std::pmr::vector<std::reference_wrapper<Root> > &getRoots() const;
    };
}


#endif //SCRIPTIUM_DATABASE_BUILDER_WORD_H
