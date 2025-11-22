#include "TorahSectionPackageManager.h"

#include "../../../../../Utils/Logger/Logger.h"

namespace scrptm {
    TorahSectionPackageManager::TorahSectionPackageManager(std::string_view path) : validator(path, sectionCount),
        reader(path, sectionCount), assembler(path, sectionCount) {
    }

    std::vector<std::unique_ptr<TorahSectionAssembled> > TorahSectionPackageManager::giveAssembledSections() const {
        validator.validate();
        Logger::LogDebug("All package folders and their content are validated.");
        std::vector<std::unique_ptr<TorahSectionPackage> > packages = reader.read();
        Logger::LogDebug("All section package files has been read.");

        std::vector<std::unique_ptr<TorahSectionAssembled> > assembled = assembler.assembleAndGive(std::move(packages));

        Logger::LogDebug("All section packages are assembled.");



        return assembled;
    }
} // scrptm
