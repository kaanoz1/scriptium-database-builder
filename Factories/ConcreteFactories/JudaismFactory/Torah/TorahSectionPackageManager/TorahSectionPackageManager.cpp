#include "TorahSectionPackageManager.h"

namespace scrptm {
    TorahSectionPackageManager::TorahSectionPackageManager(std::string_view path) : validator(path, sectionCount),
        reader(path, sectionCount), assembler(path, sectionCount) {
    }

    std::vector<std::unique_ptr<TorahSectionAssembled> > TorahSectionPackageManager::giveAssembledSections() const {
        validator.validate();

        std::vector<std::unique_ptr<TorahSectionPackage> > packages = reader.read();

        std::vector<std::unique_ptr<TorahSectionAssembled> > assembled = assembler.assembleAndGive(std::move(packages));

        return std::move(assembled);
    }
} // scrptm
