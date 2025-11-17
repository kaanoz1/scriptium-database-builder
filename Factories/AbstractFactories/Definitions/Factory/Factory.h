#ifndef SCRIPTIUM_DATABASE_BUILDER_FACTORY_H
#define SCRIPTIUM_DATABASE_BUILDER_FACTORY_H

namespace scrptm {
    class Factory {
    public:
        Factory(const Factory &) = delete;

        Factory(Factory &&) = delete;

        Factory &operator=(const Factory &) = delete;

        Factory &operator=(Factory &&) = delete;

        virtual ~Factory() = default;
    };
}

#endif
