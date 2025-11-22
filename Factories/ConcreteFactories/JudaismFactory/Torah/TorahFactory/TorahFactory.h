#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHFACTORY_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHFACTORY_H
#include "../../../../AbstractFactories/ScriptureFactory/ScriptureFactory.h"
#include "../../../../ConcreteFactories/JudaismFactory/Torah/TorahSectionPackageManager/TorahSectionPackageManager.h"

namespace scrptm {
    class TorahFactory final : ScriptureFactory {
        TorahSectionPackageManager manager;

    public:
        TorahFactory();


        std::unique_ptr<Scripture> construct() const override;
    };
} // scrptm

#endif
