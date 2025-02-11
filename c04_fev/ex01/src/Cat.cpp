#include "../headers/Cat.hpp"

Cat::Cat() :
	Animal("Cat")
{
    this->_brain = new Brain();
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
        delete _brain;
        this->_brain = other._brain;
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete _brain;
}


void Cat::makeSound() const
{
    std::cout << "Miaouuuuu" << std::endl;
}

Brain *Cat::getBrain() const
{
    return (this->_brain);
}


