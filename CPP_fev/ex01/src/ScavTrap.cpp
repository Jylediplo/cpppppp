#include "../headers/ScavTrap.hpp"

ScavTrap::ScavTrap() :
    ClapTrap()
{
    std::cout << "Default scavtrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) :
    ClapTrap( other )
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
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

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _HitPts = 100;
    _EnergyPts = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap constructor called for " << name << std::endl;
}

void ScavTrap::guardGate( void )
{
    std::cout << "ScavTrap named "
              << this->_name
              << " is now in Gate keeper mode."
              << std::endl;
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

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}