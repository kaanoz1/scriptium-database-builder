#ifndef SCRIPTIUM_DATABASE_BUILDER_VERSEFACTORY_H
#define SCRIPTIUM_DATABASE_BUILDER_VERSEFACTORY_H
#include "../../../ModelHierarchies/ScriptureHierarchy/Verse/Verse.h"
#include "../Definitions/SingleFactory/SingleFactory.h"

namespace scrptm {
    class VerseFactory : public SingleFactory<Verse>{
        ~VerseFactory() = default;

        virtual Verse construct() const override = 0;
    };
} // scrptm

#endif