#include "../headers/Animal.hpp"
#include "../headers/Dog.hpp"
#include "../headers/Cat.hpp"
#include "../headers/WrongAnimal.hpp"
#include "../headers/WrongCat.hpp"
#include "../headers/Brain.hpp"


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



// int main()
// {

//     const int numAnimals = 4;
//     Animal *animals[numAnimals];

//     for (int i = 0; i < numAnimals / 2; i++)
//     {
//         animals[i] = new Dog();
//     }
//     for (int i = numAnimals / 2; i < numAnimals; i++)
//     {
//         animals[i] = new Cat();
//     }

//     for (int i = 0; i < numAnimals; i++)
//     {
//         delete animals[i];
//     }

//     return 0;
// }

int main()
{
    Cat original;
    Cat copy = original; // Utilise le constructeur de copie

    // Vérifiez que les adresses des Brains sont différentes
    std::cout << "Original Brain address: " << original.getBrain() << std::endl;
    std::cout << "Copy Brain address: " << copy.getBrain() << std::endl;

    // Modifiez la copie et vérifiez que l'original n'est pas affecté
    copy.getBrain()->setIdea(0, "New idea");
    std::cout << "Original's first idea: " << original.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy's first idea: " << copy.getBrain()->getIdea(0) << std::endl;

    return 0;
}




