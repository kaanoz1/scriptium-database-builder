#include "Factories/ConcreteFactories/JudaismFactory/Torah/Torah/Torah.h"
#include "Factories/ConcreteFactories/JudaismFactory/Torah/TorahFactory/TorahFactory.h"
#include "Inspectors/ScriptureInspector/ScriptureInspector.h"
#include "Writers/DatabasePool/DatabasePool.h"

int main() {
     scrptm::DatabasePool database_pool;

    database_pool.connect();

    scrptm::TorahFactory torah_factory{};

    const std::unique_ptr<scrptm::Scripture> torah = torah_factory.construct();

    database_pool.writeScripture(*torah);

    return 0;
}
