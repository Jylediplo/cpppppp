#include "../headers/ClapTrap.hpp"

int main() {
    ClapTrap clapTrap("leo");

    clapTrap.attack("Target");
    clapTrap.takeDamage(9);
    clapTrap.beRepaired(2);
    for (int i = 0; i < 9; ++i)
	{
        clapTrap.attack("Target");
    }
    clapTrap.beRepaired(1);
    return 0;
}


