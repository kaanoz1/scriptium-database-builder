#include "TorahSectionPackage.h"

namespace scrptm {
    TorahSectionPackage::TorahSectionPackage(std::unique_ptr<const TorahVariationFile> usualFile,
                        std::unique_ptr<const TorahVariationFile> simplifiedFile,
                        std::unique_ptr<const TorahVariationFile> noVowelFile,
                        std::unique_ptr<const TorahSectionWordFile> wordFile) : usualFile(std::move(usualFile)),
                                                                              simplifiedFile(std::move(simplifiedFile)),
                                                                              noVowelFile(std::move(noVowelFile)),
                                                                              wordFile(std::move(wordFile)) {
    }

    const TorahVariationFile &TorahSectionPackage::getUsualFile() const {
        return *(this->usualFile);
    }

    const TorahVariationFile &TorahSectionPackage::getSimplifiedFile() const {
        return *(this->simplifiedFile);
    }

    const TorahVariationFile &TorahSectionPackage::getNoVowelFile() const {
        return *(this->noVowelFile);
    }

    const TorahSectionWordFile &TorahSectionPackage::getWordFile() const {
        return *(this->wordFile);
    }
} // scrptm
