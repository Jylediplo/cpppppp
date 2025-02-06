#include "../headers/ClapTrap.hpp"

int main(void)
{
	ClapTrap un("leo");
	ClapTrap deux("Tom");
	un.attack("tom");
	deux.takeDamage(5);
	deux.attack("leo");
	deux.takeDamage(5);
	deux.takeDamage(7);
	deux.attack("leo");

}

