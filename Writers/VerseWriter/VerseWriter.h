#ifndef SCRIPTIUM_DATABASE_BUILDER_VERSEWRITER_H
#define SCRIPTIUM_DATABASE_BUILDER_VERSEWRITER_H

#include <nanodbc.h>
#include <optional>
#include <vector>
#include <memory>

#include "../../ModelHierarchies/ScriptureHierarchy/Verse/Verse.h"
#include "../../ModelHierarchies/ScriptureHierarchy/Word/Word.h"

namespace scrptm {
    class VerseWriter {
        std::optional<unsigned long long> verseId;
        nanodbc::connection &connection;
        unsigned long long chapterId;

    public:
        explicit VerseWriter(nanodbc::connection &connection, unsigned long long chapterId);

        void write(const Verse &verse);


        std::optional<unsigned long long> checkIfVerseExist(const Verse& verse);

        unsigned long long insertVerse(const Verse &verse);

        void writeWords(unsigned long long verseId, const std::vector<std::unique_ptr<Word>> &words);
    };
} // scrptm

#endif