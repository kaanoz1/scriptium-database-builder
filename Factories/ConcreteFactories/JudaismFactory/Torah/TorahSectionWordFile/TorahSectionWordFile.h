#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHSECTIONWORDFILE_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHSECTIONWORDFILE_H
#include <memory>
#include <vector>

#include "../TorahRawChapterOfWordFile/TorahRawChapterOfWordFile.h"

namespace scrptm {
    class TorahSectionWordFile {
        const std::vector<std::unique_ptr<const TorahRawChapterOfWordFile>> chapters;

    public:
        explicit TorahSectionWordFile(std::vector<std::unique_ptr<const TorahRawChapterOfWordFile>> chapters);

        [[nodiscard]] const std::vector<std::unique_ptr<const TorahRawChapterOfWordFile>>& getChapters() const;
    };
} // scrptm

#endif