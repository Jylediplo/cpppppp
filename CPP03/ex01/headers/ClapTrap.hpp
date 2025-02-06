#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
	protected:
	std::string _name;
	int _HitPts;
	int _EnergyPts;
	int _attackDamage;
	ClapTrap();

	public:
	ClapTrap(const ClapTrap &other);
	ClapTrap(std::string name);
	ClapTrap operator=(const ClapTrap &other);
	virtual ~ClapTrap();
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
 	void beRepaired(unsigned int amount);
};

#endif