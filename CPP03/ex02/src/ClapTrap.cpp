#include "../headers/ClapTrap.hpp"
#include <iostream>

// Default constructor
ClapTrap::ClapTrap() :
    _name("Default ClapTrap"),
    _HitPts(10),
    _EnergyPts(10),
    _attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

// Parameterized constructor
ClapTrap::ClapTrap(std::string name) :
    _name(name),
    _HitPts(10),
    _EnergyPts(10),
    _attackDamage(0)
{
    std::cout << "ClapTrap constructor called for " << name << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other) :
    _name(other._name),
    _HitPts(other._HitPts),
    _EnergyPts(other._EnergyPts),
    _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

// Copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_HitPts = other._HitPts;
        this->_EnergyPts = other._EnergyPts;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

// Destructor
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called for " << this->_name << std::endl;
}

// Attack function
void ClapTrap::attack(const std::string& target)
{
    if (this->_EnergyPts == 0)
    {
        std::cout << "ClapTrap " << this->_name << " has no energy to attack " << target << std::endl;
        return;
    }
    if (this->_HitPts == 0)
    {
        std::cout << "ClapTrap " << this->_name << " is already dead" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_EnergyPts--;
}

// Take damage function
void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage" << std::endl;
    if (amount >= this->_HitPts)
        this->_HitPts = 0; // Prevent underflow
    else
        this->_HitPts -= amount;
}

// Be repaired function
void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " points of damage!" << std::endl;
    if (this->_HitPts + amount > 10) // Cap at 10
        this->_HitPts = 10;
    else
        this->_HitPts += amount;
    this->_EnergyPts--;
}