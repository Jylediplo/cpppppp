#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    // Constructors and destructor
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &other);
    ScavTrap& operator=(const ScavTrap &other);
    ~ScavTrap();

    // Special function
	void attack(const std::string &target);
    void guardGate();
};

#endif