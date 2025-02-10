#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
	protected:
	std::string _name;
	unsigned int _HitPts;
	unsigned int _EnergyPts;
	unsigned int _attackDamage;

	public:
	ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap(std::string name);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
 	void beRepaired(unsigned int amount);
};

#endif