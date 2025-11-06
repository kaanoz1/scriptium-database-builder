//
// Created by prag on 11/6/25.
//

#include "Miner.h"

#include <iostream>

template<typename TInputFile, typename TOutput>
scrptm::Miner<TInputFile, TOutput>::Miner(std::unique_ptr<Loader<TInputFile> > loader,
                                          std::unique_ptr<Validator<TInputFile> > validator,
                                          std::unique_ptr<Builder<TInputFile, TOutput> > builder) : m_loader(std::move(
        loader)),
    m_validator(std::move(validator)),
    m_builder(std::move(builder)) {
    assert(m_loader != nullptr && "Loader must not be null");
    assert(m_validator != nullptr && "Validator must not be null");
    assert(m_builder != nullptr && "Builder must not be null");
}


template<typename TInputFile, typename TOutput>
const TOutput &scrptm::Miner<TInputFile, TOutput>::create() const {
    TInputFile data = m_loader->load();
    try {
        if (!m_validator->validate(data))
            throw std::runtime_error("Verify failed.");
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        throw;
    }

    return m_builder->build(data);
}
