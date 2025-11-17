#ifndef SCRIPTIUM_DATABASE_BUILDER_SINGLEFACTORY_H
#define SCRIPTIUM_DATABASE_BUILDER_SINGLEFACTORY_H


namespace scrptm {
    template<typename T>
    class SingleFactory {

    public:
        virtual ~SingleFactory() = default;
        virtual T construct() const = 0;
    };
}

#endif
