#include "TorahRawWord.h"

#include <algorithm>
#include <format>
#include <iostream>
#include <limits>
#include <ostream>
#include <regex>
#include <stdexcept>

#include "../../../../../Utils/Logger/Logger.h"

namespace scrptm {
    TorahRawWord::TorahRawWord(const std::string text, const std::string lemma,
                               const unsigned int index) : text(text), lemma(lemma), index(index),
                                                           lemmaId(calculateLemmaId()) {
    }

    unsigned int TorahRawWord::getIndex() const {
        return this->index;
    }

    std::string_view TorahRawWord::getLemma() const {
        return this->lemma;
    }

    std::string TorahRawWord::copyLemma() const {
        return this->lemma;
    }


    unsigned int TorahRawWord::calculateLemmaId() const {
        const std::string lemmaStr = this->copyLemma();

        if (lemmaStr.empty()) {
            std::cerr << "Uyarı: Boş lemma string'i." << std::endl;
            return 0;
        }


        const std::regex lemma_regex("(\\d+)");
        std::smatch match;


        if (std::regex_search(lemmaStr, match, lemma_regex)) {
            if (match.size() > 1) {
                const std::string &numberPart = match[1].str();

                try {
                    const unsigned long id = std::stoul(numberPart);

                    if (id > std::numeric_limits<unsigned int>::max()) {
                        std::cerr << "Hata: Lemma ID, unsigned int sınırını aştı." << std::endl;
                        return 0;
                    }

                    return static_cast<unsigned int>(id);
                } catch (const std::exception &e) {
                    std::cerr << "Hata: Lemma ID string'den sayıya dönüştürülürken hata: "
                            << numberPart << " -> " << e.what() << std::endl;
                    return 0;
                }
            }
        }
        Logger::LogWarning(std::format("Could not extract the lemma. Lemma string: {}. Designating 0", lemmaStr));
        return 0;
    }

    unsigned int TorahRawWord::getLemmaId() const {
        return this->lemmaId;
    }


    std::string_view TorahRawWord::getText() const {
        return this->text;
    }

    std::string TorahRawWord::giveText() {
        return std::move(this->text);
    }
}
