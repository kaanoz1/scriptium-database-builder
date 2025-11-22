
#ifndef SCRIPTIUM_DATABASE_BUILDER_SCRIPTUREINSPECTOR_H
#define SCRIPTIUM_DATABASE_BUILDER_SCRIPTUREINSPECTOR_H

#include <memory>
#include <tabulate/table.hpp>
#include "../../ModelHierarchies/ScriptureHierarchy/Scripture/Scripture.h"
#include "../../Utils/Logger/Logger.h"

namespace scrptm {
    class ScriptureInspector {
        const std::shared_ptr<Scripture> scripturePtr;

    public:
        explicit ScriptureInspector(const std::shared_ptr<Scripture> &scripture)
            : scripturePtr(scripture) {
        }

        void inspect() const {
            tabulate::Table scriptureTable;

            if (scripturePtr == nullptr) {
                Logger::LogFatal("Scripture ref passed in ScriptureInspector is null.");
                throw std::invalid_argument("The scripture is null");
            }

            std::cout << "Scripture name: " << scripturePtr->getName() << std::endl;

            auto& scriptureMeanings =  scripturePtr->getMeanings();

            std::cout << "Scripture meanings:\n";



            //TODO: Will be implemented

        }
    };
}


#endif
