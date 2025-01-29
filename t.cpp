#include <iostream>

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
{

	Weapon ok;
	test(ok);
	std::cout << "second :" << ok.getNb() << std::endl;

}