#include "../headers/Brain.hpp"
#include <stdlib.h>
Brain::Brain()
{
    std::cout << "Default Brain constructor called" << std::endl;
    for(int i = 0; i < 100; i++)
    {
        this->_ideas[i] = "Ideas";
    }
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = other;
}


Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain copy assignement operator called" << std::endl;
    if (this != &other)
    {
        for(int i = 0; i < 100; i++)
            this->_ideas[i] = other._ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}



