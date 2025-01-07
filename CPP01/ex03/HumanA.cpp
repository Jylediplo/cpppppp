#include "HumanA.hpp"

void HumanA::attack(void)
{
    std::cout << this->name <<
    "attacks with their " << this->weapon.getType();
}

HumanA::HumanA(std::string newName, Weapon newWeapon):
name(newName), weapon(newWeapon)
{};


