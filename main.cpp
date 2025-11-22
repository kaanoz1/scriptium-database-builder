
#include "Factories/ConcreteFactories/JudaismFactory/Torah/TorahFactory/TorahFactory.h"

int main() {
    const scrptm::TorahFactory factory{};

   std::unique_ptr<scrptm::Scripture> torah = factory.construct();

    return 0;
}
