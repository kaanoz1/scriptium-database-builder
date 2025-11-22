#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHRAWVERSE_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHRAWVERSE_H
#include <string>

namespace scrptm {
    class TorahRawVerse {
        const unsigned short index;
        std::string text;

    public:
        TorahRawVerse(unsigned short index, std::string text);

        [[nodiscard]] unsigned short getIndex() const;
        [[nodiscard]] std::string_view getText() const;
        [[nodiscard]] std::string giveText();
    };
} // scrptm

#endif