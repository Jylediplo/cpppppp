#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "../headers/Weapon.hpp"

class HumanB
{
    private:
    Weapon *weapon;
    std::string name;

    public:
    void attack();
    HumanB();
    void setWeapon(Weapon &weapon);
    HumanB(std::string newName);
};

#endif