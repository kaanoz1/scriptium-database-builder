#ifndef SCRIPTIUM_DATABASE_BUILDER_CHAPTER_H
#define SCRIPTIUM_DATABASE_BUILDER_CHAPTER_H
#include <string_view>
#include <vector>

#include "../ChapterMeaning/ChapterMeaning.h"
#include "../Verse/Verse.h"

namespace scrptm {
    class Chapter {
    private:
        const unsigned short number;
        const std::string name;
        std::vector<std::unique_ptr<Verse> > verses;
        std::vector<std::unique_ptr<ChapterMeaning> > meanings;

    public:
        Chapter(unsigned short number, std::string name,
                std::vector<std::unique_ptr<Verse> > &&verses,
                std::vector<std::unique_ptr<ChapterMeaning> > &&meanings);

        [[nodiscard]] unsigned short getNumber() const;

        [[nodiscard]] std::string_view getName() const;

        [[nodiscard]] const std::vector<std::unique_ptr<Verse> > &getVerses() const;

        [[nodiscard]] const std::vector<std::unique_ptr<ChapterMeaning> > &getMeanings() const;

        [[nodiscard]] size_t getVerseCount() const;
    };
}

#endif
