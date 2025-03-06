#include "../headers/Bureaucrat.hpp"

#define RUN(code, errorMessage)    \
    try                                     \
    {                                       \
        code;                               \
    }                                       \
    catch (const std::exception &e)         \
    {                                       \
        std::cerr << errorMessage << ": " << e.what() << std::endl; \
    }

int main()
{
    try
    {
        RUN(
            Bureaucrat b1("romain", 1);
            std::cout << b1 << std::endl;
            b1.decrementGrade();
            std::cout << b1 << std::endl;,
            "Bureaucrat b1 Error"
        );

        RUN(
            Bureaucrat b2("loic", 150);
            std::cout << b2 << std::endl;
            b2.incrementGrade();
            std::cout << b2 << std::endl;,
            "Bureaucrat b2 Error"
        );

        RUN(
            Bureaucrat b3("error", 151);,
            "Bureaucrat b3 Error"
        );
    }
    catch (const std::exception &e)
    {
        std::cerr << "Unexpected Error: " << e.what() << std::endl;
    }

    return 0;
}

