
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
        const std::string_view name;
        const std::pmr::vector<std::reference_wrapper<Verse> > &verses;
        const std::pmr::vector<std::reference_wrapper<ChapterMeaning> > &meanings;

    public:
        Chapter(unsigned short number, std::string_view name,
                const std::pmr::vector<std::reference_wrapper<Verse> > &verses,
                const std::pmr::vector<std::reference_wrapper<ChapterMeaning> > &meanings);

        [[nodiscard]] const unsigned short getNumber() const;

        [[nodiscard]] const std::string_view getName() const;

        [[nodiscard]] const std::pmr::vector<std::reference_wrapper<Verse> > &getVerses() const;

        [[nodiscard]] const std::pmr::vector<std::reference_wrapper<ChapterMeaning> > &getMeanings() const;
    };
}

#endif
