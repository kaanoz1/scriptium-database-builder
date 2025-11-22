#include "TorahWordFactory.h"

#include <algorithm>

#include "../TorahRootFactory/TorahRootFactory.h"

namespace scrptm {
    TorahWordFactory::TorahWordFactory(std::unique_ptr<TorahRawWord> &&word):  word(std::move(word)) {
        this->rootFactories.push_back(std::make_unique<TorahRootFactory>(this->word->getLemmaId()));
    }

    std::unique_ptr<Word> TorahWordFactory::construct() const {
        std::vector<std::unique_ptr<Root> > roots{};

        for (const auto &rootFactory: this->rootFactories)
            roots.emplace_back(rootFactory->construct());

        auto text = this->word->giveText();

        return std::make_unique<Word>(this->word->getIndex() + 1, text, text, text, std::move(roots));
    }
} // scrptm
