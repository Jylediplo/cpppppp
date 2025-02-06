#include "../headers/FragTrap.hpp"
#include <iostream>

// Default constructor
FragTrap::FragTrap() : ClapTrap()
{
    _HitPts = 100;
    _EnergyPts = 100;
    _attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

// Parameterized constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _HitPts = 100;
    _EnergyPts = 100;
    _attackDamage = 30;
    std::cout << "FragTrap constructor called for " << name << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

// Copy assignment operator
FragTrap& FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

// Destructor
FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called for " << this->_name << std::endl;
}

// Special function
void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->_name << " requests a high five!" << std::endl;
}