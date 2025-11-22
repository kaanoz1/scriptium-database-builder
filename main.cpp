
#include "Factories/ConcreteFactories/JudaismFactory/Torah/TorahFactory/TorahFactory.h"
#include "Inspectors/ScriptureInspector/ScriptureInspector.h"

int main() {
    const scrptm::TorahFactory factory{};

   const std::unique_ptr<scrptm::Scripture> torah = factory.construct();

    const scrptm::ScriptureInspector inspector{};

    inspector.inspect(*torah);



    return 0;
}
