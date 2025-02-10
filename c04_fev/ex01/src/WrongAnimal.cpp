#include "../headers/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() :
	_type("Wrong")
{
    std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal::WrongAnimal(const std::string &type)
{
    std::cout << "Animal constructor called" << std::endl;
    this->_type = type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}
void WrongAnimal::makeSound() const
{
    std::cout << "WRONGGGG" << std::endl;
}

const std::string &WrongAnimal::getType() const
{
   return (this->_type);
}



