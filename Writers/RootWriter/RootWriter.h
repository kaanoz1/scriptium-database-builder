#ifndef SCRIPTIUM_DATABASE_BUILDER_ROOTWRITER_H
#define SCRIPTIUM_DATABASE_BUILDER_ROOTWRITER_H

#include <nanodbc.h>
#include <optional>
#include <vector>
#include <memory>

#include "../../ModelHierarchies/ScriptureHierarchy/Root/Root.h"
#include "../../ModelHierarchies/ScriptureHierarchy/Meaning/Meaning.h"

namespace scrptm {
    class RootWriter {
        std::optional<unsigned long long> rootId;
        nanodbc::connection &connection;

    public:
        explicit RootWriter(nanodbc::connection &connection);

        unsigned long long write(const Root &root);

        std::optional<unsigned long long> checkIfRootExist(const Root& root);

        unsigned long long insertRoot(const Root &root);
    };
} // scrptm

#endif