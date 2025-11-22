#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAH_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAH_H
#include <algorithm>

#include "../../../../../ModelHierarchies/ScriptureHierarchy/Scripture/Scripture.h"

namespace scrptm {
    class Torah : public Scripture {
    public:
        explicit Torah(std::vector<std::unique_ptr<Section> > sections) ;
    };
} // scrptm

#endif
