#ifndef SCRIPTIUM_DATABASE_BUILDER_WORDWRITER_H
#define SCRIPTIUM_DATABASE_BUILDER_WORDWRITER_H

#include <nanodbc.h>
#include <optional>
#include <vector>
#include <memory>

#include "../../ModelHierarchies/ScriptureHierarchy/Word/Word.h"
#include "../../ModelHierarchies/ScriptureHierarchy/Meaning/Meaning.h"
#include "../../ModelHierarchies/ScriptureHierarchy/Transliteration/Transliteration.h"

namespace scrptm {
    class WordWriter {
        std::optional<unsigned long long> wordId;
        nanodbc::connection &connection;
        unsigned long long verseId;

    public:
        explicit WordWriter(nanodbc::connection &connection, unsigned long long verseId);

        void write(const Word &word);

        unsigned long long findLanguageIdByCode(const std::string &langCode);

        std::optional<unsigned long long> checkIfWordExist(const Word& word);

        unsigned long long insertWord(const Word &word);

        void matchRoots(unsigned long long wordId, const std::vector<unsigned long long>& rootIds);

        std::vector<unsigned long long> writeRoots(unsigned long long targetWordId, const std::vector<std::unique_ptr<Root>>& root);
    };
} // scrptm

#endif