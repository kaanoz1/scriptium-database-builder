#ifndef SCRIPTIUM_DATABASE_BUILDER_CHAPTERFACTORY_H
#define SCRIPTIUM_DATABASE_BUILDER_CHAPTERFACTORY_H
#include <memory>
#include <vector>

#include "../../../ModelHierarchies/ScriptureHierarchy/Chapter/Chapter.h"
#include "../../../ModelHierarchies/ScriptureHierarchy/Verse/Verse.h"
#include "../VerseFactory/VerseFactory.h"

namespace scrptm {
    class ChapterFactory: SingleFactory<Chapter> {
    protected:
        std::vector<std::unique_ptr<VerseFactory>> verseFactories;

    public:
        ~ChapterFactory() override = default;

         [[nodiscard]] std::unique_ptr<Chapter> construct() const override = 0;
    };
} // scrptm

#endif