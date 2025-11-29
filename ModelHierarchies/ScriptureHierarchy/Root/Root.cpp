#include "Root.h"

#include <algorithm>
#include <utility>

namespace scrptm {
    Root::Root(std::string latin, std::string own)
        : latin(std::move(latin)),
          own(std::move(own)) {
    }


    const std::string Root::getLatin() const {
        return this->latin;
    }

    const std::string Root::getOwn() const {
        return this->own;
    }
}
