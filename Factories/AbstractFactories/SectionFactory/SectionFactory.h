#ifndef SCRIPTIUM_DATABASE_BUILDER_SECTIONFACTORY_H
#define SCRIPTIUM_DATABASE_BUILDER_SECTIONFACTORY_H
#include <memory>

#include "../../../ModelHierarchies/ScriptureHierarchy/Scripture/Scripture.h"
#include "../../../ModelHierarchies/ScriptureHierarchy/Section/Section.h"
#include "../Definitions/SingleFactory/SingleFactory.h"

namespace scrptm {
    class SectionFactory : public SingleFactory<Section>{
        std::vector<std::unique_ptr<SectionFactory>> sectionFactory;

    public:
        ~SectionFactory() override = default;

        [[nodiscard]] std::unique_ptr<Section> construct() const override = 0;
     };
} // scrptm

#endif