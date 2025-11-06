//
// Created by prag on 11/6/25.
//

#ifndef SCRIPTIUM_DATABASE_BUILDER_VALIDATOR_H
#define SCRIPTIUM_DATABASE_BUILDER_VALIDATOR_H

namespace scrptm {
    template<typename TFile>
    class Validator {
    public:
        /*
         @brief This function should throw errors when it encounters error or defects in that file it verifies.
         */
        virtual const bool validate(TFile inputFile) const = 0;

        virtual ~Validator() = default;
    };
}
#endif //SCRIPTIUM_DATABASE_BUILDER_VALIDATOR_H
