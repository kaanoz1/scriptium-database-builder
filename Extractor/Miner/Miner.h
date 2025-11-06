//
// Created by prag on 11/6/25.
//

#ifndef SCRIPTIUM_DATABASE_BUILDER_MINER_H
#define SCRIPTIUM_DATABASE_BUILDER_MINER_H
#include <memory>

#include "../Builder/Builder.h"
#include "../Loader/Loader.h"
#include "../Validator/Validator.h"

namespace scrptm {
    template<typename TInputFile, typename TOutput>
    class Miner {
        virtual ~Miner() = default;

    protected:
        const std::unique_ptr<Loader<TInputFile> > m_loader;
        const std::unique_ptr<Validator<TInputFile> > m_validator;
        const std::unique_ptr<Builder<TInputFile, TOutput> > m_builder;

        Miner(std::unique_ptr<Loader<TInputFile> > loader,
              std::unique_ptr<Validator<TInputFile> > validator,
              std::unique_ptr<Builder<TInputFile, TOutput> > builder);

        /*
         @brief This function forces to user to use given template
         */
        const TOutput &create() const;
    };
}


#endif //SCRIPTIUM_DATABASE_BUILDER_MINER_H
