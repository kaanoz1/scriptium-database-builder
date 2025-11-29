#ifndef SCRIPTIUM_DATABASE_BUILDER_SECTIONWRITER_H
#define SCRIPTIUM_DATABASE_BUILDER_SECTIONWRITER_H
#include <nanodbc.h>
#include <optional>

#include "../../ModelHierarchies/ScriptureHierarchy/Section/Section.h"

namespace scrptm {
    class SectionWriter {
        std::optional<unsigned long long> sectionId;
        nanodbc::connection &connection;
        unsigned long long scriptureId;

        unsigned long long findLanguageIdByCode(const std::string& langCode);

    public:
        explicit SectionWriter(nanodbc::connection &connection, unsigned long long scriptureId);

        void write(const Section &section);

        void writeMeanings(unsigned long long sectionId,
                           const std::vector<std::unique_ptr<SectionMeaning> > &sectionMeanings);

        std::optional<unsigned long long> checkIfSectionExist(const Section& section);

        unsigned long long insertSection(const Section &section);

        void writeChapters(unsigned long long sectionId, const std::vector<std::unique_ptr<Chapter>> &chapters);
    };
} // scrptm

#endif
