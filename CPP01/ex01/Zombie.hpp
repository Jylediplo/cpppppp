#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>

class Zombie
{
    private:
    std::string name;

    public:
    void announce(void);
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void setName(std::string name);
};
Zombie* zombieHorde( int N, std::string name );

#endif