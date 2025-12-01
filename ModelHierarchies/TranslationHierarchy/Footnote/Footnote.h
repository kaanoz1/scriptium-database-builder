#ifndef SCRIPTIUM_DATABASE_BUILDER_FOOTNOTE_H
#define SCRIPTIUM_DATABASE_BUILDER_FOOTNOTE_H
#include <string>

namespace scrptm {
    class Footnote {
        std::string indicator;
        unsigned long long index;
        std::string content;

    public:
        Footnote(std::string indicator, unsigned long long index, std::string content);


        std::string copyIndicator() const;

        std::string copyContent() const;

        const std::string &getIndicator() const;

        const std::string &getContent() const;


        unsigned long long getIndex() const;
    };
} // scrptm

#endif
