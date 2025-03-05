#include "../headers/Bureaucrat.hpp"
#include "../headers/ShrubberyCreationForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat b1("tom", 25);
        Bureaucrat b2("tibo", 150);

        ShrubberyCreationForm f1("home");
        RobotomyRequestForm f2("fredo");
        PresidentialPardonForm f3("gil");

        std::cout << " ||||| Sign Forms |||||" << std::endl;
        b1.signForm(f1);
        b1.signForm(f2);
        b1.signForm(f3);

        std::cout << "\n ||||||||||||| Execute Forms |||||||||||" << std::endl;
        b1.executeForm(f1);
        b1.executeForm(f2); 
        b1.executeForm(f3); 

        std::cout << "\n |||| Test Low-Grade Bureaucrat ||||" << std::endl;
        b2.executeForm(f1);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}