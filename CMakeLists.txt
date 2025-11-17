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
        ModelHierarchies/ScriptureHierarchy/Meaning/Meaning.h)

find_package(nlohmann_json REQUIRED)

target_link_libraries(scriptium_database_builder PRIVATE nlohmann_json::nlohmann_json)