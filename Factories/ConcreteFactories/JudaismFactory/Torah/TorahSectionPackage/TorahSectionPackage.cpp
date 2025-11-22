#include "TorahSectionPackage.h"

#include <algorithm>

namespace scrptm {
    TorahSectionPackage::TorahSectionPackage(std::unique_ptr<TorahVariationFile> usualFile,
                                             std::unique_ptr<TorahVariationFile> simplifiedFile,
                                             std::unique_ptr<TorahVariationFile> noVowelFile,
                                             std::unique_ptr<TorahSectionWordFile> wordFile) : usualFile(
            std::move(usualFile)),
        simplifiedFile(std::move(simplifiedFile)),
        noVowelFile(std::move(noVowelFile)),
        wordFile(std::move(wordFile)) {
    }


    std::unique_ptr<TorahVariationFile> TorahSectionPackage::giveUsualVariationFile() {
        return std::move(this->usualFile);
    }

    std::unique_ptr<TorahVariationFile> TorahSectionPackage::giveSimplifiedVariationFile() {
        return std::move(this->simplifiedFile);
    }

    std::unique_ptr<TorahVariationFile> TorahSectionPackage::giveNoVowelVariationFile() {
        return std::move(this->noVowelFile);
    }

    std::unique_ptr<TorahSectionWordFile> TorahSectionPackage::giveWordFile() {
        return std::move(this->wordFile);
    }
} // scrptm
