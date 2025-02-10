#include "../headers/Animal.hpp"
#include "../headers/Dog.hpp"
#include "../headers/Cat.hpp"
#include "../headers/WrongAnimal.hpp"
#include "../headers/WrongCat.hpp"


// int main() {
//     const Animal* meta = new Animal();
//     const Animal* j = new Dog();
//     j->getType();
//     const Animal* i = new Cat();
//     std::cout << meta->getType() << " " << std::endl;
//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     i->makeSound();
//     j->makeSound();
//     meta->makeSound();
//     delete meta;
//     delete j;
//     delete i;
//     return (0);
// }


int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const WrongAnimal* i = new WrongCat();
    std::cout << meta->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;
    return (0);
}


