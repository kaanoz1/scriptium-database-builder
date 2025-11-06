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
        const std::unique_ptr<Loader<TInputFile> > m_loader = 0;
        const std::unique_ptr<Validator<TInputFile> > m_validator = 0;
        const std::unique_ptr<Builder<TInputFile, TOutput> > m_builder = 0;

        Miner(std::unique_ptr<Loader<TInputFile> > loader,
              std::unique_ptr<Validator<TInputFile> > validator,
              std::unique_ptr<Builder<TInputFile, TOutput> > builder)
            : m_loader(std::move(loader)),
              m_validator(std::move(validator)),
              m_builder(std::move(builder)) {
            assert(m_loader != nullptr && "Loader must not be null");
            assert(m_validator != nullptr && "Validator must not be null");
            assert(m_builder != nullptr && "Builder must not be null");
        }

        /*
         @brief This function forces to user to use given template
         */
        const TOutput &create() const;
    };
}


#endif //SCRIPTIUM_DATABASE_BUILDER_MINER_H
