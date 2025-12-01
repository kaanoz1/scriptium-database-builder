cmake_minimum_required(VERSION 4.0)
project(scriptium_database_builder)

set(CMAKE_CXX_STANDARD 23)

add_executable(scriptium_database_builder main.cpp
        SearchStrategies/ExtractionStrategy/Miner/Miner.cpp
        SearchStrategies/ExtractionStrategy/Miner/Miner.h
        SearchStrategies/ExtractionStrategy/Validator/Validator.cpp
        SearchStrategies/ExtractionStrategy/Validator/Validator.h
        SearchStrategies/ExtractionStrategy/Builder/Builder.cpp
        SearchStrategies/ExtractionStrategy/Builder/Builder.h
        SearchStrategies/ExtractionStrategy/Loader/Loader.cpp
        SearchStrategies/ExtractionStrategy/Loader/Loader.h
        ModelHierarchies/ScriptureHierarchy/Root/Root.cpp
        ModelHierarchies/ScriptureHierarchy/Root/Root.h
        ModelHierarchies/ScriptureHierarchy/Word/Word.cpp
        ModelHierarchies/ScriptureHierarchy/Word/Word.h
        ModelHierarchies/ScriptureHierarchy/Verse/Verse.cpp
        ModelHierarchies/ScriptureHierarchy/Verse/Verse.h
        ModelHierarchies/ScriptureHierarchy/Language/Language.cpp
        ModelHierarchies/ScriptureHierarchy/Language/Language.h
        ModelHierarchies/ScriptureHierarchy/Transliteration/Transliteration.cpp
        ModelHierarchies/ScriptureHierarchy/Transliteration/Transliteration.h
        ModelHierarchies/ScriptureHierarchy/Chapter/Chapter.cpp
        ModelHierarchies/ScriptureHierarchy/Chapter/Chapter.h
        ModelHierarchies/ScriptureHierarchy/ChapterMeaning/ChapterMeaning.cpp
        ModelHierarchies/ScriptureHierarchy/ChapterMeaning/ChapterMeaning.h
        ModelHierarchies/ScriptureHierarchy/SectionMeaning/SectionMeaning.cpp
        ModelHierarchies/ScriptureHierarchy/SectionMeaning/SectionMeaning.h
        ModelHierarchies/ScriptureHierarchy/Section/Section.cpp
        ModelHierarchies/ScriptureHierarchy/Section/Section.h
        ModelHierarchies/ScriptureHierarchy/Scripture/Scripture.cpp
        ModelHierarchies/ScriptureHierarchy/Scripture/Scripture.h
        ModelHierarchies/ScriptureHierarchy/ScriptureMeaning/ScriptureMeaning.cpp
        ModelHierarchies/ScriptureHierarchy/ScriptureMeaning/ScriptureMeaning.h
        Constants/Constants.h
        ModelHierarchies/ScriptureHierarchy/Meaning/Meaning.cpp
        ModelHierarchies/ScriptureHierarchy/Meaning/Meaning.h
        Utils/Logger/Logger.cpp
        Utils/Logger/Logger.h
        Inspectors/ScriptureInspector/ScriptureInspector.cpp
        Inspectors/ScriptureInspector/ScriptureInspector.h
        Factories/AbstractFactories/Definitions/Factory/Factory.cpp
        Factories/AbstractFactories/Definitions/Factory/Factory.h
        Factories/AbstractFactories/Definitions/SingleFactory/SingleFactory.cpp
        Factories/AbstractFactories/Definitions/SingleFactory/SingleFactory.h
        Factories/AbstractFactories/Definitions/MultipleFactory/MultipleFactory.cpp
        Factories/AbstractFactories/Definitions/MultipleFactory/MultipleFactory.h
        Factories/AbstractFactories/RootFactory/RootFactory.cpp
        Factories/AbstractFactories/RootFactory/RootFactory.h
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahRawWord/TorahRawWord.cpp
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahRawWord/TorahRawWord.h
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahRawVerseOfWordFile/TorahRawVerseOfWordFile.cpp
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahRawVerseOfWordFile/TorahRawVerseOfWordFile.h
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahRawChapterOfWordFile/TorahRawChapterOfWordFile.cpp
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahRawChapterOfWordFile/TorahRawChapterOfWordFile.h
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahSectionWordFile/TorahSectionWordFile.cpp
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahSectionWordFile/TorahSectionWordFile.h
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahRawVerse/TorahRawVerse.cpp
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahRawVerse/TorahRawVerse.h
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahRawChapter/TorahRawChapter.cpp
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahRawChapter/TorahRawChapter.h
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahVariationFile/TorahVariationFile.cpp
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahVariationFile/TorahVariationFile.h
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahSectionPackage/TorahSectionPackage.cpp
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahSectionPackage/TorahSectionPackage.h
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahSectionPackageReader/TorahSectionPackageReader.cpp
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahSectionPackageReader/TorahSectionPackageReader.h
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahSectionPackageValidator/TorahSectionPackageValidator.cpp
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahSectionPackageValidator/TorahSectionPackageValidator.h
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahVerseAssembled/TorahVerseAssembled.cpp
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahVerseAssembled/TorahVerseAssembled.h
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahChapterAssembled/TorahChapterAssembled.cpp
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahChapterAssembled/TorahChapterAssembled.h
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahSectionAssembled/TorahSectionAssembled.cpp
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahSectionAssembled/TorahSectionAssembled.h
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahSectionPackageAssembler/TorahSectionPackageAssembler.cpp
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahSectionPackageAssembler/TorahSectionPackageAssembler.h
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahSectionPackageManager/TorahSectionPackageManager.cpp
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahSectionPackageManager/TorahSectionPackageManager.h
        Factories/AbstractFactories/WordFactory/WordFactory.cpp
        Factories/AbstractFactories/WordFactory/WordFactory.h
        Factories/AbstractFactories/VerseFactory/VerseFactory.cpp
        Factories/AbstractFactories/VerseFactory/VerseFactory.h
        Factories/AbstractFactories/ChapterFactory/ChapterFactory.cpp
        Factories/AbstractFactories/ChapterFactory/ChapterFactory.h
        Factories/AbstractFactories/SectionFactory/SectionFactory.cpp
        Factories/AbstractFactories/SectionFactory/SectionFactory.h
        Factories/AbstractFactories/ScriptureFactory/ScriptureFactory.cpp
        Factories/AbstractFactories/ScriptureFactory/ScriptureFactory.h
        Factories/ConcreteFactories/JudaismFactory/Torah/Torah/Torah.cpp
        Factories/ConcreteFactories/JudaismFactory/Torah/Torah/Torah.h
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahRootRepository/TorahRootRepository.cpp
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahRootRepository/TorahRootRepository.h
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahRootFactory/TorahRootFactory.cpp
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahRootFactory/TorahRootFactory.h
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahWordFactory/TorahWordFactory.cpp
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahWordFactory/TorahWordFactory.h
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahVerseFactory/TorahVerseFactory.cpp
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahVerseFactory/TorahVerseFactory.h
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahChapterFactory/TorahChapterFactory.cpp
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahChapterFactory/TorahChapterFactory.h
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahSectionFactory/TorahSectionFactory.cpp
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahSectionFactory/TorahSectionFactory.h
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahFactory/TorahFactory.cpp
        Factories/ConcreteFactories/JudaismFactory/Torah/TorahFactory/TorahFactory.h
        Writers/DatabasePool/DatabasePool.cpp
        Writers/DatabasePool/DatabasePool.h
        Writers/ScriptureWriter/ScriptureWriter.cpp
        Writers/ScriptureWriter/ScriptureWriter.h
        Writers/SectionWriter/SectionWriter.cpp
        Writers/SectionWriter/SectionWriter.h
        Writers/ChapterWriter/ChapterWriter.cpp
        Writers/ChapterWriter/ChapterWriter.h
        Writers/VerseWriter/VerseWriter.cpp
        Writers/VerseWriter/VerseWriter.h
        Writers/WordWriter/WordWriter.cpp
        Writers/WordWriter/WordWriter.h
        Writers/RootWriter/RootWriter.cpp
        Writers/RootWriter/RootWriter.h
        Factories/ConcreteFactories/JudaismFactory/Translation/SefariaTranslation/SefariaTranslationFile/SefariaTranslationFile.cpp
        Factories/ConcreteFactories/JudaismFactory/Translation/SefariaTranslation/SefariaTranslationFile/SefariaTranslationFile.h
        Factories/ConcreteFactories/JudaismFactory/Translation/SefariaTranslation/SefariaTranslationFileLogger/SefariaTranslationFileLogger.cpp
        Factories/ConcreteFactories/JudaismFactory/Translation/SefariaTranslation/SefariaTranslationFileLogger/SefariaTranslationFileLogger.h
        Factories/ConcreteFactories/JudaismFactory/Translation/SefariaTranslation/SefariaTranslationFileSorter/SefariaTranslationFileSorter.cpp
        Factories/ConcreteFactories/JudaismFactory/Translation/SefariaTranslation/SefariaTranslationFileSorter/SefariaTranslationFileSorter.h
        Factories/ConcreteFactories/JudaismFactory/Translation/SefariaTranslation/SefariaTranslationFileLogger/SefariaTranslationFileLogger.cpp
        Factories/ConcreteFactories/JudaismFactory/Translation/SefariaTranslation/SefariaTranslationFileLogger/SefariaTranslationFileLogger.h
        Factories/ConcreteFactories/JudaismFactory/Translation/SefariaTranslation/SefariaTranslationFileValidator/SefariaTranslationFileValidator.cpp
        Factories/ConcreteFactories/JudaismFactory/Translation/SefariaTranslation/SefariaTranslationFileValidator/SefariaTranslationFileValidator.h
        Factories/ConcreteFactories/JudaismFactory/Translation/SefariaTranslation/SefariaTranslationFileExtractor/SefariaTranslationFileExtractor.cpp
        Factories/ConcreteFactories/JudaismFactory/Translation/SefariaTranslation/SefariaTranslationFileExtractor/SefariaTranslationFileExtractor.h
        Indicators/ScriptureIndicator/ScriptureIndicator.cpp
        Indicators/ScriptureIndicator/ScriptureIndicator.h
        Indicators/SectionIndicator/SectionIndicator.cpp
        Indicators/SectionIndicator/SectionIndicator.h
)

find_package(nlohmann_json REQUIRED)
find_package(Pugixml REQUIRED)
find_package(unixodbc CONFIG REQUIRED)
find_package(nanodbc CONFIG REQUIRED)

target_link_libraries(scriptium_database_builder PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(scriptium_database_builder PRIVATE pugixml)
target_link_libraries(scriptium_database_builder PRIVATE nanodbc)