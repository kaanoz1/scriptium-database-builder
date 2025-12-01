#include "SefariaTranslationFile.h"

#include <nlohmann/json.hpp>

namespace scrptm {
    SefariaTranslationFile::SefariaTranslationFile(json translationFile)
        : sectionName(translationFile.at("title").get<std::string>()),
          translatorName(translationFile.at("versionTitle").get<std::string>()),
          texts(translationFile.at("texts").get<std::vector<std::vector<std::string> > >()) {
    }


    std::string SefariaTranslationFile::copyTranslatorName() const {
        return translatorName;
    }


    std::string SefariaTranslationFile::copySectionName() const {
        return sectionName;
    }


    std::vector<std::vector<std::string> > SefariaTranslationFile::copyTexts() const {
        return texts;
    }


    const std::string& SefariaTranslationFile::getTitle() const {
        return this->sectionName;
    }


    const std::vector<std::vector<std::string> > &SefariaTranslationFile::getTexts() const {
        return texts;
    }


    std::vector<std::vector<std::string> > SefariaTranslationFile::giveTexts() {
        return std::move(texts);
    }
} // scrptm
