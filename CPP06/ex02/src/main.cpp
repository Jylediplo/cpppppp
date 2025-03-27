#include "../headers/Base.hpp"
#include "../headers/A.hpp"
#include "../headers/B.hpp"
#include "../headers/C.hpp"
#include <cstdlib>
#include <ctime>


Base *generate(void)
{
    std::srand(std::time(0));
    int randomNb = std::rand() % 3;
    if (randomNb == 0)
		return (new A());
    else if (randomNb == 1)
		return (new B());
    else
		return (new C());
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "it is of type A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "it is of type B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "it is of type C" << std::endl;
    else
        std::cout << "unknown type" << std::endl;
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "it is A" << std::endl;
        return;
    }
    catch (...) {}
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "it is A" << std::endl;
        return;
    }
    catch (...) {}
    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "it is A" << std::endl;
        return;
    }
    catch (...) {}
}

int main(void)
{
    Base *p = generate();
    identify(p);
    identify(*p);

    delete p;
    return (0);
}
