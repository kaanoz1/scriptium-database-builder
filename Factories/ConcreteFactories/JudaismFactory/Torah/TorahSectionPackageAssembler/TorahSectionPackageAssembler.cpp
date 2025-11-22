#include "TorahSectionPackageAssembler.h"

#include <format>

#include "../../../../../Utils/Logger/Logger.h"

namespace scrptm {
    TorahSectionPackageAssembler::TorahSectionPackageAssembler(const std::string_view path,
                                                               const unsigned char sectionCount) : path(path),
        sectionCount(sectionCount) {
    }

    std::unique_ptr<TorahSectionAssembled> TorahSectionPackageAssembler::assembly(unsigned char index,
        std::unique_ptr<TorahSectionPackage> &&sectionPackage) const {
        if (sectionPackage == nullptr) {
            Logger::LogFatal("Undefined sectionPackage");
            throw std::runtime_error("Section package cannot be null");
        }

        const unsigned char sectionNumber = index + 1;

        std::unique_ptr<TorahVariationFile> usualFile = sectionPackage->giveUsualVariationFile();
        std::unique_ptr<TorahVariationFile> simplifiedFile = sectionPackage->giveSimplifiedVariationFile();
        std::unique_ptr<TorahVariationFile> noVowelFile = sectionPackage->giveNoVowelVariationFile();
        std::unique_ptr<TorahSectionWordFile> wordFile = sectionPackage->giveWordFile();


        size_t usualFileChapterLength = usualFile->getChaptersCount();
        size_t simplifiedFileChapterLength = simplifiedFile->getChaptersCount();
        size_t noVowelFileChapterLength = noVowelFile->getChaptersCount();
        size_t wordFileChapterLength = wordFile->getChapterCount();


        const std::string sectionNameHebrew = usualFile->giveTitle();
        const std::string sectionNameEnglish = usualFile->giveTitleEnglish();
        Logger::LogDebug(std::format("Section name: {}", sectionNameEnglish));

        if (!(usualFileChapterLength == simplifiedFileChapterLength && simplifiedFileChapterLength ==
              noVowelFileChapterLength && noVowelFileChapterLength == wordFileChapterLength)) {
            const std::string formattedErrorMessage = std::format(
                "Assembly error: Files has not equal lenghts of chapters. Usual file chapter length: {}. SimplifiedFile chapter length: {}. NoVowel chapter length: {}. Word file chapter length: {}. At section named: {} ({}) which has number of: {}",
                usualFileChapterLength, simplifiedFileChapterLength, noVowelFileChapterLength, wordFileChapterLength,
                sectionNameEnglish, sectionNameHebrew, sectionNumber);

            Logger::LogFatal(formattedErrorMessage);
            throw std::runtime_error("Assembly error. File chapter lengths are not equal. Check the fatal log above.");
        }

        for (size_t i = 0; i < usualFileChapterLength; i++) {
            size_t usualFileVerseLengthAtChapterI = usualFile->getVerseCountAtChapter(i);
            size_t simplifiedFileVerseLengthAtChapterI = simplifiedFile->getVerseCountAtChapter(i);
            size_t noVowelFileVerseLengthAtChapterI = noVowelFile->getVerseCountAtChapter(i);
            size_t wordFileVerseLengthAtChapterI = wordFile->getVerseCountAtChapter(i);


            if (!(usualFileVerseLengthAtChapterI == simplifiedFileVerseLengthAtChapterI &&
                  simplifiedFileVerseLengthAtChapterI == noVowelFileVerseLengthAtChapterI &&
                  noVowelFileVerseLengthAtChapterI <= //TODO: Amend this.
                  wordFileVerseLengthAtChapterI)) {
                const std::string formattedErrorMessage = std::format(
                    "Assembly error: Chapter {}'th of Section ({}, {}, {}) has not equal lengths of verses. Usual file verse length: {}. SimplifiedFile verse length: {}. NoVowel verse length: {}. Word file verse length: {}."
                    , i + 1, sectionNumber, sectionNameHebrew, sectionNameEnglish, usualFileVerseLengthAtChapterI,
                    simplifiedFileVerseLengthAtChapterI, noVowelFileVerseLengthAtChapterI,
                    wordFileVerseLengthAtChapterI);

                Logger::LogFatal(formattedErrorMessage);
                throw std::runtime_error(
                    "Assembly error. Verse lengths are not equal. Check the fatal log above.");
            }
        }


        std::vector<std::unique_ptr<TorahChapterAssembled> > chaptersAssembled{};
        size_t chapterCount = usualFileChapterLength;


        chaptersAssembled.reserve(chapterCount);

        for (size_t i = 0; i < chapterCount; i++) {
            auto usualChapter = usualFile->giveChapterAtIndex(i);
            auto simplifiedChapter = simplifiedFile->giveChapterAtIndex(i);
            auto noVowelChapter = noVowelFile->giveChapterAtIndex(i);
            auto wordFileChapter = wordFile->giveChapterAtIndex(i);


            size_t verseCount = usualChapter->getVerseCount();
            std::vector<std::unique_ptr<TorahVerseAssembled> > verses{};
            verses.reserve(verseCount);
            for (size_t j = 0; j < verseCount; j++) {
                auto usualVerse = usualChapter->giveVerseAtIndex(j);
                auto simplifiedVerse = simplifiedChapter->giveVerseAtIndex(j);
                auto noVowelVerse = noVowelChapter->giveVerseAtIndex(j);
                auto verseOfWordFile = wordFileChapter->giveVerseOfWordAtIndex(j);
                auto wordsOfVerse = verseOfWordFile->giveWords();

                auto verseAssembled = std::make_unique<TorahVerseAssembled>(
                    j, std::move(usualVerse), std::move(simplifiedVerse), std::move(noVowelVerse),
                    std::move(wordsOfVerse));
                verses.push_back(std::move(verseAssembled));
            }

            auto torahChapterAssembled = std::make_unique<TorahChapterAssembled>(
                i, std::move(verses));

            chaptersAssembled.push_back(std::move(torahChapterAssembled));
        }


        return std::make_unique<TorahSectionAssembled>(sectionNumber, sectionNameHebrew, sectionNameEnglish,
                                                       std::move(chaptersAssembled));
    }

    std::vector<std::unique_ptr<TorahSectionAssembled> > TorahSectionPackageAssembler::assembleAndGive(
        std::vector<std::unique_ptr<TorahSectionPackage> > packages) const {
        std::vector<std::unique_ptr<TorahSectionAssembled> > assembled{};

        for (size_t i = 0; i < packages.size(); i++) {
            std::unique_ptr<TorahSectionAssembled> assembledPackage = this->assembly(i, std::move(packages.at(i)));


            Logger::LogDebug(std::format("Section {} has been assembled.", i + 1));
            assembled.push_back(std::move(assembledPackage));
        }

        return std::move(assembled);
    }
} // scrptm
