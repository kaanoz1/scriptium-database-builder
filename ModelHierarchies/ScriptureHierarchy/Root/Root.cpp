#include "Root.h"

#include <algorithm>
#include <utility>

namespace scrptm {
    Root::Root(std::string latin, std::string own)
        : latin(std::move(latin)),
          own(std::move(own)) {
    }


    const std::string_view Root::getLatin() const {
        return this->latin;
    }

    const std::string_view Root::getOwn() const {
        return this->own;
    }
}
