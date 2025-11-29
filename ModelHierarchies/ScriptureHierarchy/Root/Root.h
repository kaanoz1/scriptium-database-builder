
#ifndef SCRIPTIUM_DATABASE_BUILDER_ROOT_H
#define SCRIPTIUM_DATABASE_BUILDER_ROOT_H
#include <string>
#include <string_view>

namespace scrptm {
    class Root {
        const std::string latin;
        const std::string own;

    public:
        Root(std::string latin, std::string own);

        [[nodiscard]] const std::string getLatin() const;

        [[nodiscard]] const std::string getOwn() const;
    };
}


#endif
