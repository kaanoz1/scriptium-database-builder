#ifndef SCRIPTIUM_DATABASE_BUILDER_WORD_H
#define SCRIPTIUM_DATABASE_BUILDER_WORD_H
#include <memory>
#include <string_view>
#include <vector>
#include "../Root/Root.h"

namespace scrptm {
    class Word {
    private:
        const unsigned int sequence_number;
        const std::string text;
        const std::string textSimplified;

        const std::string textWithoutVowel;
        const std::vector<std::unique_ptr<Root> > roots;

    public:
        Word(unsigned int sequence_number, std::string text,
             std::string text_simplified, std::string text_without_vowel,std::vector<std::unique_ptr<Root> > &&roots);

        [[nodiscard]] unsigned int getSequenceNumber() const;

        [[nodiscard]] std::string getText() const;

        [[nodiscard]] std::string_view getTextWithoutVowel() const;

        [[nodiscard]] std::string_view getTextSimplified() const;

        [[nodiscard]] const std::vector<std::unique_ptr<Root> > &getRoots() const;
    };
}


#endif
