#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class NoOccurenceException : public std::exception
{
    public:
        virtual const char *what() const throw();
};

template<typename T>
void easyfind(T a, int b)
{
    std::vector<int>::const_iterator it = std::find(a.begin(), a.end(), b);
    if (it != a.end())
        std::cout << "found ! : " << *it << std::endl;
    else
        throw NoOccurenceException();
}

#endif