#include "TorahSectionFactory.h"

#include <algorithm>
#include <format>

#include "../../../../../Constants/Constants.h"
#include "../../../../../Utils/Logger/Logger.h"
#include "../TorahChapterFactory/TorahChapterFactory.h"

namespace scrptm {
    TorahSectionFactory::TorahSectionFactory(
        std::unique_ptr<TorahSectionAssembled> sectionAssembled) : sectionAssembled(std::move(sectionAssembled)) {
        Logger::LogDebug(std::format("Chapters are being fetched"));
        std::vector<std::unique_ptr<TorahChapterAssembled> > chapters = this->sectionAssembled->giveChapters();
        Logger::LogDebug(std::format("Chapters are fetched"));


        for (size_t i = 0; i < chapters.size(); ++i) {
            Logger::LogDebug(std::format("Chapter factory {} are set", i + 1));
            this->chapterFactories.push_back(std::make_unique<TorahChapterFactory>(std::move(chapters.at(i))));
        }

        Logger::LogDebug("Chapter factories are set");

    }

    std::unique_ptr<Section> TorahSectionFactory::construct() const {
        auto number = this->sectionAssembled->getSectionNumber();
        auto hebrewName = this->sectionAssembled->giveSectionTitleHebrew();
        auto englishMeaning = this->sectionAssembled->giveSectionTitleInEnglish();
        std::vector<std::unique_ptr<SectionMeaning> > meanings{};
        meanings.push_back(std::make_unique<SectionMeaning>(englishMeaning, constants::General::Language::englishRef));


        std::vector<std::unique_ptr<Chapter> > chapters{};

        for (const auto &factory: this->chapterFactories)
            chapters.push_back(factory->construct());

        return std::make_unique<Section>(number, std::move(hebrewName), std::move(chapters), std::move(meanings));
    }
} // scrptm
