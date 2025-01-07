#include <Weapon.hpp>

const std::string &Weapon::getType()
{
    return (type);
}

void Weapon::setType(std::string const &newType)
{
    this->type = newType;
}

Weapon::Weapon(std::string newType) : type(newType)
{};