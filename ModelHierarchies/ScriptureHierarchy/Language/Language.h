
#ifndef SCRIPTIUM_DATABASE_BUILDER_LANGUAGE_H
#define SCRIPTIUM_DATABASE_BUILDER_LANGUAGE_H
#include <string>

namespace scrptm {
    class Language {
    private:
        const std::string_view langOwn;
        const std::string_view langEnglish;
        const std::string_view langCode;

    public:
        Language(std::string_view lang_own, std::string_view lang_english, std::string_view lang_code);

        [[nodiscard]] const std::string_view getLanguageCode() const;

        [[nodiscard]] const std::string_view getLanguageOwn() const;

        [[nodiscard]] const std::string_view getLanguageEnglish() const;
    };
}


#endif
