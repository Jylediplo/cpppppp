#include "../headers/ClapTrap.hpp"

ClapTrap::ClapTrap() :
	_name( "Default ClapTrap" ),
	_HitPts( 10 ),
	_EnergyPts( 10 ),
	_attackDamage( 0 )
{
    std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_attackDamage = other._attackDamage;
        this->_EnergyPts = other._EnergyPts;
        this->_HitPts = other._HitPts;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}


ClapTrap::ClapTrap(std::string name): _name(name), _HitPts(10), _EnergyPts(10),
_attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
};

void ClapTrap::attack(const std::string& target)
{
	if (this->_EnergyPts <= 0)
	{
		std::cout << "ClapTrap "<< this->_name << " has no energy to attack " << target << std::endl;
		return ;
	}
	if (this->_HitPts <= 0)
	{
		std::cout << "Claptrap "<< this->_name << " is already dead" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name <<" attacks " << target <<
	", causing "<< this->_attackDamage << " points of damage!" << std::endl;
	this->_EnergyPts--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage" << std::endl;
    if (amount >= this->_HitPts)
        this->_HitPts = 0;
    else
        this->_HitPts -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_EnergyPts <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " cannot be repaired because it has no energy points left!" << std::endl;
        return;
    }
    if (this->_HitPts >= 10)
    {
        std::cout << "ClapTrap " << this->_name << " cannot be repaired because it is already at full health!" << std::endl;
        return;
    }
	if (this->_HitPts <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot be repaired because already dead" << std::endl;
		return ;
	}
    std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " points of damage!" << std::endl;
    this->_HitPts += amount;
    if (this->_HitPts > 10)
        this->_HitPts = 10;
    this->_EnergyPts--;
}