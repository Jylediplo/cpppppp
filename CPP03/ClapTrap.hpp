#ifndef MAGIE_H
#define MAGIE_H

#include <iostream>

class ClapTrap
{
	private:
	std::string _name;
	int _HitPts;
	int _EnergyPts;
	int _attackDamage;

	public:
	void attack(const std::string& target)
	{
		if (this->_EnergyPts == 0)
		{
			std::cout << "no energy to attack" << std::endl;
			return ;
		}
		if (this->_HitPts == 0)
		{
			std::cout << "is already dead" << std::endl;
			return;
		}
		std::cout << "ClapTrap " << this->_name <<" attacks " <<target <<
		", causing "<< this->_attackDamage << " points of damage!" << std::endl;
		this->_EnergyPts--;
	}
	void takeDamage(unsigned int amount)
	{
		std::cout << "Claptrap " << this->_name << " takes " << amount << " damages" << std::endl;
		this->_HitPts -= amount;
		if (this->_HitPts < 0)
			this->_HitPts = 0;
	}
 	void beRepaired(unsigned int amount)
	{
		std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " points of damage!" << std::endl;
		this->_HitPts += amount;
		if (this->_HitPts > 10)
			this->_HitPts = 10;
		this->_EnergyPts--;
	}

	ClapTrap(std::string name): _name(name), _HitPts(10), _EnergyPts(10),
	_attackDamage(0)
	{};
};
#endif