//
// Created by prag on 11/6/25.
//

#ifndef SCRIPTIUM_DATABASE_BUILDER_ROOT_H
#define SCRIPTIUM_DATABASE_BUILDER_ROOT_H
#include <string_view>


class Root {
private:
    const std::string_view latin;
    const std::string_view own;
public:
    Root(const std::string_view latin, const std::string_view own)
        : latin(latin),
          own(own) {
    }

    [[nodiscard]] const std::string_view getLatin() const;
    [[nodiscard]] const std::string_view getOwn() const;
};


#endif //SCRIPTIUM_DATABASE_BUILDER_ROOT_H