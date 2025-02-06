#include "../headers/ClapTrap.hpp"
#include "../headers/ScavTrap.hpp"
#include "../headers/FragTrap.hpp"

int main()
{
    // // Test ClapTrap
    // ClapTrap clap("Clappy");
    // clap.attack("Target");
    // clap.takeDamage(5);
    // clap.beRepaired(3);

    // // Test ScavTrap
    // ScavTrap scav("Scavvy");
    // scav.attack("Target");
    // scav.guardGate();

    // Test FragTrap
    FragTrap frag("Fraggy");
    frag.attack("Target");
    frag.highFivesGuys();

    return 0;
}