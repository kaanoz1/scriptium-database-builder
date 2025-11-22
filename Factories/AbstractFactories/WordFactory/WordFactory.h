#ifndef SCRIPTIUM_DATABASE_BUILDER_WORDFACTORY_H
#define SCRIPTIUM_DATABASE_BUILDER_WORDFACTORY_H
#include <memory>

#include "../../../ModelHierarchies/ScriptureHierarchy/Word/Word.h"
#include "../Definitions/SingleFactory/SingleFactory.h"
#include "../RootFactory/RootFactory.h"

namespace scrptm {
    class WordFactory : public SingleFactory<Word> {
        std::vector<std::unique_ptr<RootFactory>> rootFactories;
    public:
        ~WordFactory() override = default;

        [[nodiscard]] std::unique_ptr<Word> construct() const override;
    };
} // scrptm

#endif