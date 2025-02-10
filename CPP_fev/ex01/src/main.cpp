#include "../headers/ScavTrap.hpp"



int main() {
    ScavTrap scavTrap("leo");

    scavTrap.attack("Target");
    scavTrap.takeDamage(10);


    scavTrap.guardGate();

    for (int i = 0; i < 5; ++i)
    {
        scavTrap.attack("Target");
    }

    return 0;
}

