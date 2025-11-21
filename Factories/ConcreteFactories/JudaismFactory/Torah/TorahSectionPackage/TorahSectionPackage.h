#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHSECTIONPACKAGE_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHSECTIONPACKAGE_H
#include "../TorahSectionWordFile/TorahSectionWordFile.h"
#include "../TorahVariationFile/TorahVariationFile.h"

namespace scrptm {
    class TorahSectionPackage {
        const TorahVariationFile usualFile;
        const TorahVariationFile simplifiedFile;
        const TorahVariationFile noVowelFile;
        const TorahSectionWordFile wordFile;

    public:
        TorahSectionPackage(TorahVariationFile variationFile, TorahVariationFile simplifiedFile,
                            TorahVariationFile noVowelFile, TorahSectionWordFile wordFile);

        [[nodiscard]] const TorahVariationFile& getUsualFile() const;
        [[nodiscard]] const TorahVariationFile& getSimplifiedFile() const;
        [[nodiscard]] const TorahVariationFile& getNoVowelFile() const;
        [[nodiscard]] const TorahSectionWordFile& getWordFile() const;
    };
} // scrptm

#endif
