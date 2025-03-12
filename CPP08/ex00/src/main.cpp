#include "../headers/easyfind.hpp"

const char * NoOccurenceException::what() const throw()
{
    return "No matching numbers found";
}

int main(void)
{
    std::vector<int>    intArray;

    intArray.push_back(5);
    intArray.push_back(4);
    intArray.push_back(3);
    intArray.push_back(2);

    try
    {
        easyfind(intArray, 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}