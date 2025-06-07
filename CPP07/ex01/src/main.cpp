// #include "../headers/iter.hpp"
#include <iostream>

template<typename T>
void anyType(T value)
{
    std::cout << "display array : " << value << std::endl;
}
template<typename T, typename U>
void iter(T &array, size_t len, U anyType)
{
    for(size_t i = 0; i < len; i++)
    {
        anyType(array[i]);
    }
}

int main(void)
{ 
    float nb[3] = {1.0f, 3, 4.5f};
    std::string sentence[] = {"tibo", "ok"};

    iter(nb, 3, anyType<float>);
    iter(sentence, 2, anyType<std::string>);


    return (0);
} 
