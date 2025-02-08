#include <iostream>
<<<<<<

	class Weapon
	{
		private:
		int nb;
		public:
		void setNb(int nou)
		{
			this->nb = nou;
		};
		int getNb()
		{
			return this->nb;
		};
	};

void test(Weapon &ok)
{
	ok.setNb(4);
	std::cout << "first : "<< ok.getNb() << std::endl;
};

int main(void)
=======
 
int main(void) 
>>>>>>> e24ca8efdc1a2db1a98a3c201806edf825d67004
{

<<<<<<< HEAD
	Weapon ok;
	test(ok);
	std::cout << "second :" << ok.getNb() << std::endl;

}
=======
	std::cin >> str;

	if (!std::cin)
		printf("not a number");
	std::cout << std::endl << "str : " << str << std::endl;
	// if (std::stoi(str) == 1)
	// 	std::cout << "bien egal à 1"; 
	return(0);

>>>>>>> e24ca8efdc1a2db1a98a3c201806edf825d67004
