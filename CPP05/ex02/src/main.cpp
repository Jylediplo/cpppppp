 #include "../headers/Bureaucrat.hpp"
#include "../headers/ShrubberyCreationForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/PresidentialPardonForm.hpp"

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
        Bureaucrat b1("tom", 72);
        Bureaucrat b2("tibo", 1);


        ShrubberyCreationForm f1("home");
        RobotomyRequestForm f2("fredo");
        PresidentialPardonForm f3("gil");

        std::cout << " ||||| Sign Forms |||||" << std::endl;
        RUN(b1.signForm(f1);, "Signing f1 Error");
        RUN(b1.signForm(f2);, "Signing f2 Error");
        // RUN(b1.signForm(f3);, "Signing f3 Error");

        std::cout << "\n ||||||||||||| Execute Forms |||||||||||" << std::endl;
        RUN(b1.executeForm(f1);, "Executing f1 Error");
        RUN(b1.executeForm(f2);, "Executing f2 Error");
        RUN(b1.executeForm(f3);, "Executing f3 Error");

        std::cout << "\n |||| Test Low-Grade Bureaucrat ||||" << std::endl;
        RUN(b2.executeForm(f1);, "Low-Grade Bureaucrat Execution Error");
    }
    catch (const std::exception &e)
    {
        std::cerr << "Unexpected Error: " << e.what() << std::endl;
    }

    return 0;
}
