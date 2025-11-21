#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHSECTIONPACKAGEVALIDATOR_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHSECTIONPACKAGEVALIDATOR_H
#include <string_view>

namespace scrptm {
    class TorahSectionPackageValidator {
        const std::string_view path;
        const unsigned char sectionCount;

    public:
        TorahSectionPackageValidator(std::string_view path, unsigned char sectionCount);

        void validate() const;
    };
} // scrptm

#endif
