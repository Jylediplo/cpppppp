#include "../headers/WrongCat.hpp"

WrongCat::WrongCat() :
	WrongAnimal("WrongCat")
{
    std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
    :WrongAnimal(other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}
WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}


void WrongCat::makeSound() const
{
    std::cout << "Wrong Miaouuuuu" << std::endl;
}



