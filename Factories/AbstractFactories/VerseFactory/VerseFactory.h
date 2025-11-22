#ifndef SCRIPTIUM_DATABASE_BUILDER_VERSEFACTORY_H
#define SCRIPTIUM_DATABASE_BUILDER_VERSEFACTORY_H
#include <memory>

#include "../../../ModelHierarchies/ScriptureHierarchy/Verse/Verse.h"
#include "../Definitions/SingleFactory/SingleFactory.h"
#include "../WordFactory/WordFactory.h"

namespace scrptm {
    class VerseFactory : public SingleFactory<Verse> {
        std::vector<std::unique_ptr<WordFactory> > wordFactories;

    public:
        ~VerseFactory() override = default;


         [[nodiscard]] std::unique_ptr<Verse> construct() const override = 0;
    };
} // scrptm

#endif
