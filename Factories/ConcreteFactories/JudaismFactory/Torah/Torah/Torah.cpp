#include "Torah.h"

#include "../../../../../Constants/Constants.h"

namespace scrptm {
    Torah::Torah(std::vector<std::unique_ptr<Section> > sections) : Scripture(
        "תורה", 't', 1,
        [] {
            std::vector<std::unique_ptr<ScriptureMeaning> > v;
            v.push_back(std::make_unique<ScriptureMeaning>("Torah", constants::General::Language::englishRef));
            return v;
        }(),
        std::move(sections)) {
    }
} // scrptm
