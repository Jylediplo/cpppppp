#include "../headers/Fixed.hpp"

Fixed::Fixed() :  _fixedNumber(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_fixedNumber = other._fixedNumber;
}

Fixed::Fixed(const int value): _fixedNumber(value << this->_bits)
{}

Fixed::Fixed(const float value) : _fixedNumber(roundf(value * (1 << this->_bits)))
{}
Fixed Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &other)
    {
        this->_fixedNumber = other._fixedNumber;
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedNumber);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedNumber = raw;
}

float Fixed::toFloat( void ) const
{
    return ((float)this->_fixedNumber / (1 << this->_bits));
}

int Fixed::toInt( void ) const
{
    return (this->_fixedNumber >> this->_bits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &obj)
{
    out << obj.toFloat();
    return out;
}
