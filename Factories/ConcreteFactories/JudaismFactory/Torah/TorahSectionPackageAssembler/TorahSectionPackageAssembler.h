#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHSECTIONPACKAGEASSEMBLER_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHSECTIONPACKAGEASSEMBLER_H
#include <algorithm>
#include <string_view>

#include "../TorahSectionAssembled/TorahSectionAssembled.h"
#include "../TorahSectionPackage/TorahSectionPackage.h"

namespace scrptm {
    class TorahSectionPackageAssembler {
        const std::string_view path;
        const unsigned char sectionCount;

        [[nodiscard]] std::unique_ptr<TorahSectionAssembled> assembly(unsigned char index,
            std::unique_ptr<TorahSectionPackage> &&sectionPackage) const;

    public:
        TorahSectionPackageAssembler(std::string_view path, unsigned char sectionCount);

        [[nodiscard]] std::vector<std::unique_ptr<TorahSectionAssembled> > assembleAndGive(
            std::vector<std::unique_ptr<TorahSectionPackage> > packages) const;
    };
} // scrptm

#endif
