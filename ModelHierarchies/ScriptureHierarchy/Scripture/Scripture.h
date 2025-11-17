//
// Created by prag on 11/6/25.
//

#ifndef SCRIPTIUM_DATABASE_BUILDER_SCRIPTURE_H
#define SCRIPTIUM_DATABASE_BUILDER_SCRIPTURE_H
#include <string_view>
#include <vector>

#include "../Section/Section.h"
#include "../ScriptureMeaning/ScriptureMeaning.h"

namespace scrptm {
     class Scripture {
        const std::string_view name;
        const unsigned char code;
        const unsigned char number;
        const std::pmr::vector<std::reference_wrapper<ScriptureMeaning> > &meanings;
        const std::pmr::vector<std::reference_wrapper<Section> > &sections;

    public:
        Scripture(std::string_view name, unsigned char code, unsigned char number,
                  const std::pmr::vector<std::reference_wrapper<ScriptureMeaning> > &meanings,
                  const std::pmr::vector<std::reference_wrapper<Section> > &sections);

        [[nodiscard]] const std::string_view getName() const;

        [[nodiscard]] const unsigned char getCode() const;

        [[nodiscard]] const unsigned char getNumber() const;

        [[nodiscard]] const std::pmr::vector<std::reference_wrapper<Section> > &getSections() const;

        [[nodiscard]] const std::pmr::vector<std::reference_wrapper<ScriptureMeaning> > &getMeanings() const;
    };
}


#endif //SCRIPTIUM_DATABASE_BUILDER_SCRIPTURE_H
