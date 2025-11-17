//
// Created by prag on 11/6/25.
//

#include "Root.h"

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
