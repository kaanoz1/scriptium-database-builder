#include "TorahSectionPackage.h"

namespace scrptm {
    TorahSectionPackage::TorahSectionPackage(TorahVariationFile usualFile, TorahVariationFile simplifiedFile,
                                             TorahVariationFile noVowelFile,
                                             TorahSectionWordFile wordFile) : usualFile(std::move(usualFile)),
                                                                              simplifiedFile(std::move(simplifiedFile)),
                                                                              noVowelFile(std::move(noVowelFile)),
                                                                              wordFile(std::move(wordFile)) {
    }

    const TorahVariationFile &TorahSectionPackage::getUsualFile() const {
        return this->usualFile;
    }

    const TorahVariationFile &TorahSectionPackage::getSimplifiedFile() const {
        return this->simplifiedFile;
    }

    const TorahVariationFile &TorahSectionPackage::getNoVowelFile() const {
        return this->noVowelFile;
    }

    const TorahSectionWordFile &TorahSectionPackage::getWordFile() const {
        return this->wordFile;
    }
} // scrptm
