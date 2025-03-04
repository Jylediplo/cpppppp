#include "../headers/Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("romain", 1);
        std::cout << b1 << std::endl;

        b1.decrementGrade();
        std::cout << b1 << std::endl;

        Bureaucrat b2("loic", 150);
        std::cout << b2 << std::endl;

        b2.incrementGrade();
        std::cout << b2 << std::endl;

        Bureaucrat b3("error", 151);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
