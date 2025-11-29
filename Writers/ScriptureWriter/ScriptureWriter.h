#ifndef SCRIPTIUM_DATABASE_BUILDER_SCRIPTUREWRITER_H
#define SCRIPTIUM_DATABASE_BUILDER_SCRIPTUREWRITER_H
#include <nanodbc.h>
#include <optional>
#include "../../ModelHierarchies/ScriptureHierarchy/Scripture/Scripture.h"

namespace scrptm {
    class ScriptureWriter {
        std::optional<unsigned long long> existingScriptureId;

        nanodbc::connection &connection;

    public:
        explicit ScriptureWriter(nanodbc::connection &connection);

        unsigned long long findLanguageIdByCode(const std::string& langCode);

        void write(const Scripture &scripture);

        void writeMeanings(unsigned long long scriptureId, const std::vector<std::unique_ptr<ScriptureMeaning>>& scriptureMeanings);

        std::optional<unsigned long long> checkIfScriptureExist();

        unsigned long long insertScripture(const Scripture &scripture);

        void writeSections(unsigned long long existingScriptureId, const std::vector<std::unique_ptr<Section>> &sections);
    };
} // scrptm

#endif
