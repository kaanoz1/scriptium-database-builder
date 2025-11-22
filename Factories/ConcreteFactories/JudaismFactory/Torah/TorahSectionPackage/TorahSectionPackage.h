#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHSECTIONPACKAGE_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHSECTIONPACKAGE_H
#include "../TorahSectionWordFile/TorahSectionWordFile.h"
#include "../TorahVariationFile/TorahVariationFile.h"

namespace scrptm {
    class TorahSectionPackage {
        std::unique_ptr<TorahVariationFile> usualFile;
        std::unique_ptr<TorahVariationFile> simplifiedFile;
        std::unique_ptr<TorahVariationFile> noVowelFile;
        std::unique_ptr<TorahSectionWordFile> wordFile;

    public:
        TorahSectionPackage(std::unique_ptr<TorahVariationFile> usualFile,
                            std::unique_ptr<TorahVariationFile> simplifiedFile,
                            std::unique_ptr<TorahVariationFile> noVowelFile,
                            std::unique_ptr<TorahSectionWordFile> wordFile);


        [[nodiscard]] std::unique_ptr<TorahVariationFile> giveUsualVariationFile();

        [[nodiscard]] std::unique_ptr<TorahVariationFile> giveSimplifiedVariationFile();

        [[nodiscard]] std::unique_ptr<TorahVariationFile> giveNoVowelVariationFile();

        [[nodiscard]] std::unique_ptr<TorahSectionWordFile> giveWordFile();
    };
} // scrptm

#endif
