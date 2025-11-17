//
// Created by prag on 11/6/25.
//

#ifndef SCRIPTIUM_DATABASE_BUILDER_SECTION_H
#define SCRIPTIUM_DATABASE_BUILDER_SECTION_H
#include <string_view>

#include "../Chapter/Chapter.h"
#include "../SectionMeaning/SectionMeaning.h"

namespace scrptm {
    class Section {
    private:
        const unsigned short number;
        const std::string_view name;
        const std::pmr::vector<std::reference_wrapper<Chapter> > &chapters;
        const std::pmr::vector<std::reference_wrapper<SectionMeaning> > &meanings;

    public:
        Section(unsigned short number, const std::string_view name,
                const std::pmr::vector<std::reference_wrapper<Chapter> > &chapters,
                const std::pmr::vector<std::reference_wrapper<SectionMeaning> > &meanings);


        [[nodiscard]] const unsigned short getNumber() const;

        [[nodiscard]] const std::string_view getName() const;

        [[nodiscard]] const std::pmr::vector<std::reference_wrapper<Chapter> > &getChapters() const;

        [[nodiscard]] const std::pmr::vector<std::reference_wrapper<SectionMeaning> > &getMeanings() const;
    };
}


#endif //SCRIPTIUM_DATABASE_BUILDER_SECTION_H
