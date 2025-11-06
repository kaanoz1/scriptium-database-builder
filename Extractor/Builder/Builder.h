//
// Created by prag on 11/6/25.
//

#ifndef SCRIPTIUM_DATABASE_BUILDER_BUILDER_H
#define SCRIPTIUM_DATABASE_BUILDER_BUILDER_H

template <typename TFileInput, typename TOutput>
class Builder {
    public:
        virtual ~Builder() = default;

        /*
         @brief This functions build the declared input via travelling along the file it has given.
         */
        virtual const TOutput& build(TFileInput file) const = 0;
};


#endif //SCRIPTIUM_DATABASE_BUILDER_BUILDER_H