#include "../headers/Dog.hpp"

Dog::Dog() :
	Animal("Dog")
{
    std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other)
    :Animal(other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}
Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "WOUUUUUUUUUUF" << std::endl;
}






