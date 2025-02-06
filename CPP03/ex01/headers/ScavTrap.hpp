#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        ScavTrap();
    public :
        ScavTrap(const ScavTrap &other);
        ScavTrap(std::string name);
        ScavTrap operator=(const ScavTrap &other);
        ~ScavTrap();
        void attack(const std::string& target);
        void guardGuate( void );
};

#endif