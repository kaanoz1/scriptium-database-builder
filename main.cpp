#include <iostream>

#include "Factories/ConcreteFactories/JudaismFactory/Torah/TorahRootFactory/TorahRootFactory.h"
#include "Factories/ConcreteFactories/JudaismFactory/Torah/TorahRootRepository/TorahRootRepository.h"

int main() {
    scrptm::TorahRootFactory rootFactory(1974);

    const auto root = rootFactory.construct();

    std::cout << root->getOwn() << " "  << root->getLatin() << std::endl;

    return 0;
}
