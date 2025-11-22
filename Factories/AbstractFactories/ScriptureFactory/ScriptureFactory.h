#ifndef SCRIPTIUM_DATABASE_BUILDER_SCRIPTUREFACTORY_H
#define SCRIPTIUM_DATABASE_BUILDER_SCRIPTUREFACTORY_H
#include <memory>

#include "../../../ModelHierarchies/ScriptureHierarchy/Scripture/Scripture.h"
#include "../Definitions/SingleFactory/SingleFactory.h"
#include "../SectionFactory/SectionFactory.h"

namespace scrptm {
    class ScriptureFactory : SingleFactory<Scripture> {
        std::vector<std::unique_ptr<SectionFactory>> sectionFactory;

    public:
        ~ScriptureFactory() override = default;

        [[nodiscard]] std::unique_ptr<Scripture> construct() const override;

    };
} // scrptm

#endif