//
// Created by prag on 11/6/25.
//

#ifndef SCRIPTIUM_DATABASE_BUILDER_LOADER_H
#define SCRIPTIUM_DATABASE_BUILDER_LOADER_H

namespace scrptm {
    template<typename TInputFile>
    class Loader {
    public:
        virtual ~Loader() = default;


        /*
         @brief This function should load the file or data into the memory for given strategy.
         */
        virtual const TInputFile &load() const = 0;
    };
}
#endif //SCRIPTIUM_DATABASE_BUILDER_LOADER_H
