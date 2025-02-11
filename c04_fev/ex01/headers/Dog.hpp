#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "../headers/Brain.hpp"

class Dog : public Animal
{
	public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	~Dog();
	void makeSound() const;

	private:
	Brain *_brain;
};

#endif