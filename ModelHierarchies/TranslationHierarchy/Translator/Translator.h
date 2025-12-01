#ifndef SCRIPTIUM_DATABASE_BUILDER_TRANSLATOR_H
#define SCRIPTIUM_DATABASE_BUILDER_TRANSLATOR_H
#include <optional>
#include <string>

#include "../../ScriptureHierarchy/Language/Language.h"

namespace scrptm {
    class Translator {
        std::string name;
        std::optional<std::string> url;
        const Language& language;

    public:
        Translator(std::string name, std::optional<std::string> url, const Language& language);

        std::string copyName() const;
        const std::string& getName() const;

        std::optional<std::string> copyUrl() const;

        const Language& getLanguage() const;


    };
} // scrptm

#endif
