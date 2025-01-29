#include "../headers/HumanA.hpp"

void HumanA::attack(void)
{
    std::cout << this->name <<
    " attacks with his " << this->weapon.getType() << std::endl;
}

HumanA::HumanA(std::string newName, Weapon &newWeapon):
weapon(newWeapon), name(newName)
{};
