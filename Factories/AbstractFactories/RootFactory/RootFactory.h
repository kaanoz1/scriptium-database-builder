#ifndef SCRIPTIUM_DATABASE_BUILDER_ROOTFACTORY_H
#define SCRIPTIUM_DATABASE_BUILDER_ROOTFACTORY_H
#include "../../../ModelHierarchies/ScriptureHierarchy/Root/Root.h"
#include "../Definitions/SingleFactory/SingleFactory.h"

namespace scrptm {
    class RootFactory : public SingleFactory<Root> {
    public:
        ~RootFactory() override = default;

        [[nodiscard]] Root construct() const override = 0;
    };
}

#endif
