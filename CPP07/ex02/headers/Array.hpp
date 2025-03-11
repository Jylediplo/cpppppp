#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<class T>
class Array
{
    public:
        Array<T>();
        Array<T>(unsigned int n);
    private:
        T *_array;
};

#endif