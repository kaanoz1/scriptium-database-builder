#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHRAWWORD_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHRAWWORD_H
#include <string>

namespace scrptm {
    class TorahRawWord {
         std::string text;
         std::string lemma;
         unsigned int index;

    public:
        TorahRawWord(std::string text, std::string lemma,
                     unsigned int index);

        [[nodiscard]] std::string_view getText() const;

        [[nodiscard]] std::string_view getLemma() const;

        [[nodiscard]] unsigned int getIndex() const;

        [[nodiscard]] unsigned int getLemmaId() const;

        [[nodiscard]] std::string giveText();
    };
}

#endif
