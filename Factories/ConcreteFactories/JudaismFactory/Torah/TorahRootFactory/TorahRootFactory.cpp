#include "TorahRootFactory.h"

#include <algorithm>


namespace scrptm {
    TorahRootRepository scrptm::TorahRootFactory::rootRepository;


    TorahRootFactory::TorahRootFactory(const unsigned int lemmaId) : lemmaId(lemmaId) {
    }


    std::unique_ptr<Root> TorahRootFactory::construct() const {
        std::unique_ptr<Root> root = scrptm::TorahRootFactory::rootRepository.find(lemmaId);


        return std::move(root);
    }
} // scrptm
