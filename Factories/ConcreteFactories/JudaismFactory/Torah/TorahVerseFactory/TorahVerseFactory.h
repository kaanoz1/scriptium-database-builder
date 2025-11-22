#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHVERSEFACTORY_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHVERSEFACTORY_H
#include <memory>

#include "../../../../AbstractFactories/VerseFactory/VerseFactory.h"
#include "../TorahVerseAssembled/TorahVerseAssembled.h"

namespace scrptm {
    class TorahVerseFactory final : public VerseFactory{
        std::unique_ptr<TorahVerseAssembled> verseAssembled;

    public:
        explicit TorahVerseFactory(std::unique_ptr<TorahVerseAssembled> verseAssembled);

        std::unique_ptr<Verse> construct() const override;
    };
} // scrptm

#endif