#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal(const std::string &type);
	WrongAnimal &operator=(const WrongAnimal &other);
	virtual ~WrongAnimal();
	const std::string &getType() const;
	void makeSound() const;

	protected:
	std::string _type;
};

#endif