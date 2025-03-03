 #include "../headers/Animal.hpp"

Animal::Animal() :
	_type("Unknown")
{
    std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Animal::Animal(const std::string &type)
{
    std::cout << "Animal constructor called" << std::endl;
    this->_type = type;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}
void Animal::makeSound() const
{
    std::cout << "GRRRRRRRRR" << std::endl;
}

const std::string &Animal::getType() const
{
   return (this->_type);
}

