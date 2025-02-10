#include "../headers/Cat.hpp"

Cat::Cat() :
	Animal("Cat")
{
    std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other)
    :Animal(other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}
Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}


void Cat::makeSound() const
{
    std::cout << "Miaouuuuu" << std::endl;
}



