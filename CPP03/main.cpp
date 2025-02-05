 #include "ClapTrap.hpp"


int main(void)
{
 	ClapTrap un("leo");
	ClapTrap deux("lucas");

	un.attack("lucas");
	deux.beRepaired(2);
	return (0);
}


