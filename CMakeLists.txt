cmake_minimum_required(VERSION 4.0)
project(scriptium_database_builder)

set(CMAKE_CXX_STANDARD 23)

add_executable(scriptium_database_builder main.cpp
        Extractor/Miner/Miner.cpp
        Extractor/Miner/Miner.h
        Extractor/Validator/Validator.cpp
        Extractor/Validator/Validator.h
        Extractor/Builder/Builder.cpp
        Extractor/Builder/Builder.h
        Extractor/Loader/Loader.cpp
        Extractor/Loader/Loader.h
        Model/Root/Root.cpp
        Model/Root/Root.h
        Model/Word/Word.cpp
        Model/Word/Word.h
        Model/Verse/Verse.cpp
        Model/Verse/Verse.h
        Model/Language/Language.cpp
        Model/Language/Language.h
        Model/Transliteration/Transliteration.cpp
        Model/Transliteration/Transliteration.h
        Model/Chapter/Chapter.cpp
        Model/Chapter/Chapter.h
        Model/ChapterMeaning/ChapterMeaning.cpp
        Model/ChapterMeaning/ChapterMeaning.h
        Model/SectionMeaning/SectionMeaning.cpp
        Model/SectionMeaning/SectionMeaning.h
        Model/Section/Section.cpp
        Model/Section/Section.h
        Model/Scripture/Scripture.cpp
        Model/Scripture/Scripture.h
        Model/ScriptureMeaning/ScriptureMeaning.cpp
        Model/ScriptureMeaning/ScriptureMeaning.h)
