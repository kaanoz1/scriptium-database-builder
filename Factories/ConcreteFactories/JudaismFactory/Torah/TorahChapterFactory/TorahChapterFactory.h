#ifndef SCRIPTIUM_DATABASE_BUILDER_TORAHCHAPTERFACTORY_H
#define SCRIPTIUM_DATABASE_BUILDER_TORAHCHAPTERFACTORY_H
#include "../../../../AbstractFactories/ChapterFactory/ChapterFactory.h"
#include "../TorahChapterAssembled/TorahChapterAssembled.h"

namespace scrptm {
    class TorahChapterFactory final : public ChapterFactory{


        std::unique_ptr<TorahChapterAssembled> chapterAssembled;


    public:
        explicit TorahChapterFactory(std::unique_ptr<TorahChapterAssembled> chapterAssembled);

        std::unique_ptr<Chapter> construct() const override;




    };
} // scrptm

#endif