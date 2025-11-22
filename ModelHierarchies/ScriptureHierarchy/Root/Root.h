
#ifndef SCRIPTIUM_DATABASE_BUILDER_ROOT_H
#define SCRIPTIUM_DATABASE_BUILDER_ROOT_H
#include <string>
#include <string_view>

namespace scrptm {
    class Root {
        const std::string latin;
        const std::string own;

    public:
        Root(const std::string latin, std::string own);

        [[nodiscard]] const std::string_view getLatin() const;

        [[nodiscard]] const std::string_view getOwn() const;
    };
}


#endif
