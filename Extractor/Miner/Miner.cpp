//
// Created by prag on 11/6/25.
//

#include "Miner.h"

#include <iostream>


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
