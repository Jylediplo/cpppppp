#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>

class Zombie
{
    private:
    std::string name;

    public:
    void announce(void);
    Zombie* newZombie( std::string name );
    void randomChump( std::string name );
};

#endif