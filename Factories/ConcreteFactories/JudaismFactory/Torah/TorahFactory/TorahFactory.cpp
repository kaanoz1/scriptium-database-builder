#include "TorahFactory.h"

#include <format>

#include "../../../../../Utils/Logger/Logger.h"
#include "../Torah/Torah.h"
#include "../TorahSectionFactory/TorahSectionFactory.h"

namespace scrptm {
    TorahFactory::TorahFactory() : manager("/home/prag/CLionProjects/scriptium-database-builder/data/torah/verse") {
        std::vector<std::unique_ptr<TorahSectionAssembled>> sectionsAssembled = manager.giveAssembledSections();

        for (size_t i = 0; i < sectionsAssembled.size(); i++) {
            Logger::LogDebug(std::format("Section factory {} are set", i + 1));

                    this->sectionFactory.push_back(std::make_unique<TorahSectionFactory>(std::move(sectionsAssembled.at(i))));
        }

        Logger::LogDebug("Section factorires are set");
    }

    std::unique_ptr<Scripture> TorahFactory::construct() const {
        std::vector<std::unique_ptr<Section> > sections{};

        unsigned int x = 1;
        for (const auto &factory: this->sectionFactory) {
            Logger::LogDebug(std::format("Section {} is constructed", x++));
            sections.push_back(factory->construct());
        }


        Logger::LogInformation("Torah has been successfully created!");
        return std::make_unique<Torah>(std::move(sections));
    }
} // scrptm
