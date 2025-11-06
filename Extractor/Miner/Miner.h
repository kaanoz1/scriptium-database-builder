//
// Created by prag on 11/6/25.
//

#ifndef SCRIPTIUM_DATABASE_BUILDER_MINER_H
#define SCRIPTIUM_DATABASE_BUILDER_MINER_H
#include <memory>

#include "../Builder/Builder.h"
#include "../Loader/Loader.h"
#include "../Validator/Validator.h"

template <typename TInputFile, typename TOutput>
class Miner {
private:
    std::unique_ptr<Loader<TInputFile>> m_loader = 0;
    std::unique_ptr<Validator<TInputFile>> m_validator = 0;
    std::unique_ptr<Builder<TInputFile, TOutput>> m_builder = 0;

    /*
     @brief This function forces to user to use given template
     */
    const TOutput& create() const;

};


#endif //SCRIPTIUM_DATABASE_BUILDER_MINER_H