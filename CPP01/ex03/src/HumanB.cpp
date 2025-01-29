#include "../headers/HumanB.hpp"

void HumanB::attack(void)
{
    if (!(this->weapon))
    {
        std::cout << this->name << " attacks with his barehands" << std::endl;
        return ;
    }
    std::cout << this->name <<
    " attacks with his " << this->weapon->getType() << std::endl;
};

HumanB::HumanB()
{};

HumanB::HumanB(std::string newName): weapon(NULL), name(newName)
{};

void HumanB::setWeapon(Weapon &newWeapon)
{
    this->weapon = &newWeapon;
}
