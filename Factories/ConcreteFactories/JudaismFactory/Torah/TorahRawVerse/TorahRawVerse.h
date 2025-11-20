#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHRAWVERSE_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHRAWVERSE_H
#include <string_view>

namespace scrptm {
    class TorahRawVerse {
        const unsigned short index;
        const std::string_view text;

    public:
        TorahRawVerse(unsigned short index, std::string_view text);

        [[nodiscard]] unsigned short getIndex() const;
        [[nodiscard]] std::string_view getText() const;
    };
} // scrptm

#endif