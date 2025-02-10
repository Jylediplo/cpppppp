#include "../headers/Brain.hpp"

Brain::Brain() :
	_type("Unknown")
{
    std::cout << "Default Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Brain::Brain(const std::string &type)
{
    std::cout << "Brain constructor called" << std::endl;
    this->_type = type;
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}
void Brain::makeSound() const
{
    std::cout << "GRRRRRRRRR" << std::endl;
}

const std::string &Brain::getType() const
{
   return (this->_type);
}



