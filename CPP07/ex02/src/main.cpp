#include "../headers/Array.hpp"

template<typename T>
Array<T>::Array()
{
    std::cout << "Basic function" << std::endl;
    this->_array = new T();
}
template<typename T>
Array<T>::Array(unsigned int n)
{
    std::cout << "unsigned function" << std::endl;
    this->_array = new T[n];
}

int main(void)
{
    Array<int> one(5);
    int *a = new int(1);
    std::cout << *a << std::endl;
    return (0); 
}