#ifndef SCRIPTIUM_DATABASE_BUILDER_SCRIPTUREINSPECTOR_H
#define SCRIPTIUM_DATABASE_BUILDER_SCRIPTUREINSPECTOR_H

#include <format>
#include <memory>
#include <tabulate/table.hpp>
#include "../../ModelHierarchies/ScriptureHierarchy/Scripture/Scripture.h"
#include "../../Utils/Logger/Logger.h"

namespace scrptm {
    class ScriptureInspector {
        unsigned char getUserInput(unsigned char max_value, char &selection_char) const;


        void runChapterSelection(const Section &section) const;
        void printChapterDetails(const Chapter &chapter) const;
        void runSectionSelection(
            const std::vector<std::unique_ptr<Section> > &sections) const;

        void printSections(const std::vector<std::unique_ptr<Section> > &sections) const;

        void printSection(const std::unique_ptr<Section> &section) const;

    public:
        ScriptureInspector();


        void inspect(const Scripture &scripture) const;
    };
}


#endif
