#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "../headers/Data.hpp"
#include <iostream>
#include <stdint.h>

class Serializer {
public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);

private:
        Serializer();
        ~Serializer() {}
};

#endif
