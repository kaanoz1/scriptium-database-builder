#ifndef SCRIPTIUM_DATABASE_BUILDER_DATABASEPOOL_H
#define SCRIPTIUM_DATABASE_BUILDER_DATABASEPOOL_H
#include <cstdlib>
#include <nanodbc/nanodbc.h>
#include "../../Utils/Logger/Logger.h"

#include "../../ModelHierarchies/ScriptureHierarchy/Scripture/Scripture.h"
namespace scrptm {

    class DatabasePool {
        const char *connectionString;

        nanodbc::connection connection_;

    public:
        DatabasePool();

        ~DatabasePool();

        void printConnectionString() const noexcept;

        [[nodiscard]] const char *getConnectionString() const noexcept;

        bool connect();

        [[nodiscard]]  nanodbc::connection& getConnection() noexcept;


        [[nodiscard]] bool isConnected() const;

        void writeScripture(const Scripture& scripture);


    };
} // scrptm

#endif
