#ifndef SCRIPTIUM_DATABASE_BUILDER_SECTION_H
#define SCRIPTIUM_DATABASE_BUILDER_SECTION_H
#include <string_view>

#include "../Chapter/Chapter.h"
#include "../SectionMeaning/SectionMeaning.h"

namespace scrptm {
    class Section {
    private:
        const unsigned short number;
        const std::string name;
        std::vector<std::unique_ptr<Chapter> > chapters;
        std::vector<std::unique_ptr<SectionMeaning> > meanings;

    public:
        Section(unsigned short number, std::string name,
                std::vector<std::unique_ptr<Chapter> > &&chapters,
                std::vector<std::unique_ptr<SectionMeaning> > &&meanings);


        [[nodiscard]] unsigned short getNumber() const;

        [[nodiscard]] std::string getName() const;

        [[nodiscard]] const std::vector<std::unique_ptr<Chapter> > &getChapters() const;

        [[nodiscard]] size_t getChapterCount() const;
        [[nodiscard]] size_t getVerseCount() const;

        [[nodiscard]] const std::vector<std::unique_ptr<SectionMeaning> > &getMeanings() const;
    };
}


#endif
