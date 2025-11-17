#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHRAWWORD_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHRAWWORD_H
#include <optional>
#include <string_view>

namespace scrptm {
    class TorahRawWord {
        const std::string_view text;
        const std::string_view lemma;
        const unsigned int index;

    public:
        TorahRawWord(std::string_view text, std::string_view lemma,
                     unsigned int index);

        const std::string_view getText() const;

        const std::string_view getLemma() const;

        const unsigned int getIndex() const;

        const unsigned short getLemmaId() const;
    };
}

#endif
