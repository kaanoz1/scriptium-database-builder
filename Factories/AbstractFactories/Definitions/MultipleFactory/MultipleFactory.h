#ifndef SCRIPTIUM_DATABASE_BUILDER_MULTIPLEFACTORY_H
#define SCRIPTIUM_DATABASE_BUILDER_MULTIPLEFACTORY_H
#include <memory>
#include <vector>

#include "../Factory/Factory.h"

namespace scrptm {
    template<typename T>
    class MultipleFactory : public Factory {
    public:
        ~MultipleFactory() override = default;


        virtual std::vector<std::unique_ptr<const T> > construct() const = 0;
    };
}

#endif
