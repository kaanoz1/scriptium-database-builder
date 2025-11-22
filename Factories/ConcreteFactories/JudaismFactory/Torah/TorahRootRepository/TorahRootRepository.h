#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHROOTREPOSITORY_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHROOTREPOSITORY_H
#include <map>
#include <string>
#include <nlohmann/json_fwd.hpp>

#include "../../../../../ModelHierarchies/ScriptureHierarchy/Root/Root.h"

namespace scrptm {
    using json = nlohmann::json;

    class TorahRootRepository {
        const std::string sourceFilePath{"./data/torah/root/data.json"};
        std::map<unsigned int, std::string> rootMap;

    private:
        json readSourceFile() const;

        void validateJson(const json &source) const;

        unsigned int extractHeader(const std::string &mappingValue);

        void fillMap(const json &source);

    public:
        TorahRootRepository();


        Root find(unsigned int) const;
    };
} // scrptm

#endif
