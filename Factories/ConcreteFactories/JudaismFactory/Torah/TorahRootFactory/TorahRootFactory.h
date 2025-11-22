#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHROOTFACTORY_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHROOTFACTORY_H
#include "../../../../../ModelHierarchies/ScriptureHierarchy/Root/Root.h"
#include "../../../../AbstractFactories/Definitions/SingleFactory/SingleFactory.h"
#include "../../../../AbstractFactories/RootFactory/RootFactory.h"
#include "../TorahRootRepository/TorahRootRepository.h"


namespace scrptm {
    class TorahRootFactory final : public RootFactory {
        static TorahRootRepository rootRepository;

        const unsigned int lemmaId;

    public:
        explicit TorahRootFactory(unsigned int lemmaId);

        [[nodiscard]] std::unique_ptr<Root> construct() const override;
    };
} // scrptm


#endif
