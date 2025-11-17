#ifndef SCRIPTIUM_DATABASE_BUILDER_SINGLEFACTORY_H
#define SCRIPTIUM_DATABASE_BUILDER_SINGLEFACTORY_H


namespace scrptm {
    template<typename T>
    class SingleFactory {
        ~SingleFactory() = default;

        virtual const T construct() const = 0;
    };
}

#endif //SCRIPTIUM_DATABASE_BUILDER_SINGLEFACTORY_H
