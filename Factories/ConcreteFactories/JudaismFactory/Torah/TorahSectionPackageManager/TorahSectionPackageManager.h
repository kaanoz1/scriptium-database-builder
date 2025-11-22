#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHSECTIONPACKAGEMANAGER_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHSECTIONPACKAGEMANAGER_H
#include "../../../../../Constants/Constants.h"
#include "../TorahSectionPackageValidator/TorahSectionPackageValidator.h"
#include "../TorahSectionPackageReader/TorahSectionPackageReader.h"
#include "../TorahSectionPackageAssembler/TorahSectionPackageAssembler.h"
#include "../TorahSectionAssembled/TorahSectionAssembled.h"

namespace scrptm {
    class TorahSectionPackageManager {
        const unsigned char sectionCount = constants::Judaism::Torah::sectionCount;

        const TorahSectionPackageValidator validator;
        const TorahSectionPackageReader reader;
        const TorahSectionPackageAssembler assembler;

    public:
        explicit TorahSectionPackageManager(std::string_view path);


        [[nodiscard]] std::vector<std::unique_ptr<TorahSectionAssembled> > giveAssembledSections() const;
    };
} // scrptm

#endif
