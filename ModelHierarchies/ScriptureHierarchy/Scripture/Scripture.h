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
        const char code;
        const int number;
        std::vector<std::unique_ptr<ScriptureMeaning> > meanings;
        std::vector<std::unique_ptr<Section> > sections;

    public:
        Scripture(std::string &&name, char code, int number,
                  std::vector<std::unique_ptr<ScriptureMeaning> > &&meanings,
                  std::vector<std::unique_ptr<Section> > &&sections);

        [[nodiscard]] std::string getName() const;

        [[nodiscard]] char getCode() const;

        [[nodiscard]] int getNumber() const;

        [[nodiscard]] const std::vector<std::unique_ptr<Section> > &getSections() const;

        [[nodiscard]] const std::vector<std::unique_ptr<ScriptureMeaning> > &getMeanings() const;
    };
}


#endif
