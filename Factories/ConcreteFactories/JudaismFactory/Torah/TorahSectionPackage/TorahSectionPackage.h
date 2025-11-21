#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHSECTIONPACKAGE_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHSECTIONPACKAGE_H
#include "../TorahSectionWordFile/TorahSectionWordFile.h"
#include "../TorahVariationFile/TorahVariationFile.h"

namespace scrptm {
    class TorahSectionPackage {
        std::unique_ptr<const TorahVariationFile> usualFile;
        std::unique_ptr<const TorahVariationFile> simplifiedFile;
        std::unique_ptr<const TorahVariationFile> noVowelFile;
        std::unique_ptr<const TorahSectionWordFile> wordFile;

    public:
        TorahSectionPackage(std::unique_ptr<const TorahVariationFile> usualFile,
                        std::unique_ptr<const TorahVariationFile> simplifiedFile,
                        std::unique_ptr<const TorahVariationFile> noVowelFile,
                        std::unique_ptr<const TorahSectionWordFile> wordFile);

        [[nodiscard]] const TorahVariationFile& getUsualFile() const;
        [[nodiscard]] const TorahVariationFile& getSimplifiedFile() const;
        [[nodiscard]] const TorahVariationFile& getNoVowelFile() const;
        [[nodiscard]] const TorahSectionWordFile& getWordFile() const;
    };
} // scrptm

#endif
