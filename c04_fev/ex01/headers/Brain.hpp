#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
	Brain();
	Brain(const Brain &other);
	Brain(const std::string &type);
	Brain &operator=(const Brain &other);
	virtual ~Brain();
	const std::string &getType() const;
	virtual void makeSound() const;

	protected:
	std::string _type;

	private:
	std::string _ideas[100];
};

#endif