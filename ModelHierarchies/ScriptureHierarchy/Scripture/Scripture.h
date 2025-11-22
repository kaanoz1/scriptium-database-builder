#ifndef SCRIPTIUM_DATABASE_BUILDER_SCRIPTURE_H
#define SCRIPTIUM_DATABASE_BUILDER_SCRIPTURE_H
#include <memory>
#include <string_view>
#include <vector>

#include "../Section/Section.h"
#include "../ScriptureMeaning/ScriptureMeaning.h"

namespace scrptm {
    class Scripture {
        const std::string name;
        const unsigned char code;
        const unsigned char number;
        std::vector<std::unique_ptr<ScriptureMeaning> > meanings;
        std::vector<std::unique_ptr<Section> > sections;

    public:
        Scripture(std::string &&name, unsigned char code, unsigned char number,
                  std::vector<std::unique_ptr<ScriptureMeaning> >&& meanings,
                  std::vector<std::unique_ptr<Section> >&& sections);

        [[nodiscard]] std::string_view getName() const;

        [[nodiscard]] unsigned char getCode() const;

        [[nodiscard]] unsigned char getNumber() const;

        [[nodiscard]] const std::vector<std::unique_ptr<Section> > &getSections() const;

        [[nodiscard]] const std::vector<std::unique_ptr<ScriptureMeaning> > &getMeanings() const;
    };
}


#endif
