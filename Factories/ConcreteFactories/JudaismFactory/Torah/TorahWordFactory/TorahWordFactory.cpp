#include "TorahWordFactory.h"

#include <algorithm>
#include <format>

#include "../../../../../Utils/Logger/Logger.h"
#include "../TorahRootFactory/TorahRootFactory.h"

namespace scrptm {
    TorahWordFactory::TorahWordFactory(std::unique_ptr<TorahRawWord> &&word) : word(std::move(word)) {
        this->rootFactories.push_back(std::make_unique<TorahRootFactory>(this->word->getLemmaId()));
        Logger::LogDebug("Root factories are set.");
    }

    std::unique_ptr<Word> TorahWordFactory::construct() const {
        std::vector<std::unique_ptr<Root> > roots{};

        for (const auto &rootFactory: this->rootFactories) {
            if (rootFactory == nullptr) {
                Logger::LogWarning(std::format("En countered a null root. Word: {}, lemmaId: {}", word->getText(),
                                               word->getLemma()));
                continue;
            }

            roots.emplace_back(rootFactory->construct());
        }

        auto text = this->word->giveText();

        return std::make_unique<Word>(this->word->getIndex() + 1, text, text, text, std::move(roots));
    }
} // scrptm
