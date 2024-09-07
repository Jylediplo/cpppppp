#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    (void)name;
    Zombie *zombie = new Zombie[N];
    for(int i = 0; i < N; i++)   
    {
        if (i == 2)
            zombie[i].setName("NICO");
        else
            zombie[i].setName(name);
    }
    return (zombie);
}