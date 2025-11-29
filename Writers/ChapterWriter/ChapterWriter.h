
#ifndef SCRIPTIUM_DATABASE_BUILDER_CHAPTERWRITER_H
#define SCRIPTIUM_DATABASE_BUILDER_CHAPTERWRITER_H

#include <nanodbc.h>
#include <optional>
#include <vector>
#include <memory>

#include "../../ModelHierarchies/ScriptureHierarchy/Chapter/Chapter.h"
#include "../../ModelHierarchies/ScriptureHierarchy/ChapterMeaning/ChapterMeaning.h"
#include "../../ModelHierarchies/ScriptureHierarchy/Verse/Verse.h"

namespace scrptm {
    class ChapterWriter {
        std::optional<unsigned long long> chapterId;
        nanodbc::connection &connection;
        unsigned long long sectionId;

    public:
        explicit ChapterWriter(nanodbc::connection &connection, unsigned long long sectionId);

        void write(const Chapter &chapter);

        void writeMeanings(unsigned long long targetChapterId,
                           const std::vector<std::unique_ptr<ChapterMeaning> > &chapterMeanings);

        unsigned long long findLanguageIdByCode(const std::string &langCode);

        std::optional<unsigned long long> checkIfChapterExist(const Chapter& chapter);

        unsigned long long insertChapter(const Chapter &chapter);

        void writeVerses(unsigned long long chapterId, const std::vector<std::unique_ptr<Verse>> &verses);
    };
} // scrptm


#endif