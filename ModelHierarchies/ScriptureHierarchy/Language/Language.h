
#ifndef SCRIPTIUM_DATABASE_BUILDER_LANGUAGE_H
#define SCRIPTIUM_DATABASE_BUILDER_LANGUAGE_H
#include <string>

namespace scrptm {
    class Language {
    private:
        const std::string langOwn;
        const std::string langEnglish;
        const std::string langCode;

    public:
        Language(std::string_view lang_own, std::string_view lang_english, std::string_view lang_code);

        [[nodiscard]] const std::string getLanguageCode() const;

        [[nodiscard]] const std::string getLanguageOwn() const;

        [[nodiscard]] const std::string getLanguageEnglish() const;
    };
}


#endif
