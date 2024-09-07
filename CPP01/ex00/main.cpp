#include "Zombie.hpp"

int main(void)
{
    Zombie *zombie = newZombie("Leo");
    zombie->announce();
    delete zombie;
    randomChump("fred");
    return (0);
}