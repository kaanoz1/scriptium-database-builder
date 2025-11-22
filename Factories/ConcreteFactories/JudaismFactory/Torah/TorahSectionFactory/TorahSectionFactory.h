#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHSECTIONFACTORY_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHSECTIONFACTORY_H
#include "../../../../AbstractFactories/SectionFactory/SectionFactory.h"
#include "../TorahSectionAssembled/TorahSectionAssembled.h"

namespace scrptm {
    class TorahSectionFactory final : public SectionFactory {
        std::unique_ptr<TorahSectionAssembled> sectionAssembled;

    public:
        explicit TorahSectionFactory(std::unique_ptr<TorahSectionAssembled> sectionAssembled);


        [[nodiscard]] std::unique_ptr<Section> construct() const override;
    };
} // scrptm

#endif
