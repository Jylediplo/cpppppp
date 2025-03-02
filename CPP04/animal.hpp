 #ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>


class Animal
{
	protected:
	std::string type;
	public:
	Animal(): type("unknown")
	{
		std::cout << "An animal is born !" << std::endl;
	}
};

class Dog: public Animal
{
	public:
	Dog(std::string type)
	{
		this->type = type;
		std::cout << "A dog is born" << std::endl;
	}
	void get_type()
	{
		std::cout << this->type << std::endl;
	}
};

class Cat: public Animal
{

};

#endif
