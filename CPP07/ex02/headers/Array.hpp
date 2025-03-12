#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
    public:
        Array<T>();
        Array<T>(unsigned int n);
    private:
        T *_array;
};

#endif