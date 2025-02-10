#include "../headers/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _HitPts = 100;
    _EnergyPts = 100;
    _attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _HitPts = 100;
    _EnergyPts = 100;
    _attackDamage = 30;
    std::cout << "FragTrap constructor called for " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called for " << this->_name << std::endl;
}


void FragTrap::attack(const std::string& target)
{
	if (this->_EnergyPts <= 0)
	{
		std::cout << "FragTrap "<< this->_name << " has no energy to attack " << target << std::endl;
		return ;
	}
	if (this->_HitPts <= 0)
	{
		std::cout << "FragTrap "<< this->_name << " is already dead" << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->_name <<" attacks " << target <<
	", causing "<< this->_attackDamage << " points of damage!" << std::endl;
	this->_EnergyPts--;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->_name << " requests a high five!" << std::endl;
}