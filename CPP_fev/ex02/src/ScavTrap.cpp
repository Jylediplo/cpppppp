#include "../headers/ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
    _HitPts = 100;
    _EnergyPts = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _HitPts = 100;
    _EnergyPts = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called for " << this->_name << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_EnergyPts <= 0)
	{
		std::cout << "ScavTrap "<< this->_name << " has no energy to attack " << target << std::endl;
		return ;
	}
	if (this->_HitPts <= 0)
	{
		std::cout << "ScavTrap "<< this->_name << " is already dead" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->_name <<" attacks " << target <<
	", causing "<< this->_attackDamage << " points of damage!" << std::endl;
	this->_EnergyPts--;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}