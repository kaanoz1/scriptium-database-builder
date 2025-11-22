#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHWORDFACTORY_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHWORDFACTORY_H
#include <memory>

#include "../../../../../ModelHierarchies/ScriptureHierarchy/Word/Word.h"
#include "../../../../AbstractFactories/Definitions/SingleFactory/SingleFactory.h"
#include "../../../../AbstractFactories/WordFactory/WordFactory.h"
#include "../TorahRawWord/TorahRawWord.h"

namespace scrptm {
    class TorahWordFactory final : public WordFactory{
        std::unique_ptr<TorahRawWord> word;

    public:
        explicit TorahWordFactory(std::unique_ptr<TorahRawWord> &&word);

        std::unique_ptr<Word> construct() const override;
    };
} // scrptm

#endif