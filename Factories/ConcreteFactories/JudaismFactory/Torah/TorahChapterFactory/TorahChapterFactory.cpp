#include "TorahChapterFactory.h"

#include <algorithm>
#include <format>
#include "../../../../../Utils/Logger/Logger.h"

#include "../TorahVerseFactory/TorahVerseFactory.h"

namespace scrptm {
    TorahChapterFactory::TorahChapterFactory(
        std::unique_ptr<TorahChapterAssembled> chapterAssembled) : chapterAssembled(std::move(chapterAssembled)) {
        std::vector<std::unique_ptr<TorahVerseAssembled> > verses = this->chapterAssembled->giveVerses();

        for (size_t i = 0; i < verses.size(); ++i) {
            Logger::LogDebug(std::format("Verse factory {} are set", i + 1));
            this->verseFactories.push_back(std::make_unique<TorahVerseFactory>(std::move(verses.at(i))));
        }

            Logger::LogDebug(std::format("Verse factories are set"));

    }

    std::unique_ptr<Chapter> TorahChapterFactory::construct() const {
        const auto number = this->chapterAssembled->getIndex() + 1;
        auto name = std::to_string(number);

        std::vector<std::unique_ptr<ChapterMeaning> > chapterMeanings{};
        std::vector<std::unique_ptr<Verse> > verses{};

        for (const auto &verseFactory: this->verseFactories)
            verses.push_back(std::move(verseFactory->construct()));

        return std::make_unique<Chapter>(number, std::move(name), std::move(verses), std::move(chapterMeanings));
    }
} // scrptm
