#include "HumanB.hpp"

void HumanB::attack(void)
{
    std::cout << this->name <<
    "attacks with their " << this->weapon.getType();
};

HumanB::HumanB(std::string newName): name(newName)
{
    
};


