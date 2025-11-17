#ifndef SCRIPTIUM_DATABASE_BUILDER_FACTORY_H
#define SCRIPTIUM_DATABASE_BUILDER_FACTORY_H

namespace scrptm {
    class Factory {
    protected:
        Factory() = default;

    public:

        Factory(const Factory&) = delete;
        Factory operator=(const Factory&&) = delete;
    };
}

#endif