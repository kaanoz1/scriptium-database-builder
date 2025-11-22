#include "TorahVerseFactory.h"

#include <algorithm>

#include "../TorahWordFactory/TorahWordFactory.h"

namespace scrptm {
    TorahVerseFactory::TorahVerseFactory(std::unique_ptr<TorahVerseAssembled> verseAssembled) : verseAssembled(
        std::move(verseAssembled)) {
        std::vector<std::unique_ptr<TorahRawWord> > words = verseAssembled->giveWords();


        for (size_t i = 0; i < words.size(); ++i)
            this->wordFactories.push_back(std::make_unique<TorahWordFactory>(std::move(words.at(i))));
    }

    std::unique_ptr<Verse> TorahVerseFactory::construct() const {
        auto number = this->verseAssembled->getIndex() + 1;
        auto text = this->verseAssembled->giveUsual()->giveText();
        auto textSimplified = this->verseAssembled->giveSimplified()->giveText();
        auto textNoVowel = this->verseAssembled->giveNoVowel()->giveText();


        std::vector<std::unique_ptr<Word> > words{};
        std::vector<std::unique_ptr<Transliteration> > transliterations{};

        for (const auto &word: this->wordFactories)
            words.push_back(word->construct());


        return std::make_unique<Verse>(number, std::move(text), std::move(textSimplified), std::move(textNoVowel),
                                       std::move(words), std::move(transliterations));
    }
} // scrptm
