#ifndef SCRIPTIUM_DATABASE_BUILDER_SINGLEFACTORY_H
#define SCRIPTIUM_DATABASE_BUILDER_SINGLEFACTORY_H
#include <memory>

namespace scrptm {
    template<typename T>
    class SingleFactory {
    public:
        virtual ~SingleFactory() = default;

        virtual std::unique_ptr<T> construct() const = 0;
    };
}

#endif
