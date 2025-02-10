#include "../headers/ClapTrap.hpp"
#include "../headers/ScavTrap.hpp"
#include "../headers/FragTrap.hpp"

int main()
{

    ClapTrap clap("Clappy");
    clap.attack("Target");
    clap.takeDamage(5);
    clap.beRepaired(3);

    ScavTrap scav("Scavvy");
    scav.attack("Target");
    scav.guardGate();

    FragTrap frag("leo");
    frag.attack("Target");
    frag.highFivesGuys();

    return 0;
}