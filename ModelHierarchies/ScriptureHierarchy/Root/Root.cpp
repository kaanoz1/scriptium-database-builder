
#include "Root.h"

namespace scrptm {
    Root::Root(std::string_view latin, std::string_view own)
        : latin(latin),
          own(own) {
    }


    const std::string_view Root::getLatin() const {
        return this->latin;
    }

    const std::string_view Root::getOwn() const {
        return this->own;
    }
}
