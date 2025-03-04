#include "../headers/Bureaucrat.hpp"
#include "../headers/ShrubberyCreationForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat b1("John", 1);
        Bureaucrat b2("Doe", 150);

        ShrubberyCreationForm f1("home");
        RobotomyRequestForm f2("Alice");
        PresidentialPardonForm f3("Bob");

        std::cout << "--- Signing Forms ---" << std::endl;
        b1.signForm(f1);
        b1.signForm(f2);
        b1.signForm(f3);

        std::cout << "\n--- Executing Forms ---" << std::endl;
        b1.executeForm(f1);
        b1.executeForm(f2); 
        b1.executeForm(f3); 

        std::cout << "\n--- Testing Low-Grade Bureaucrat ---" << std::endl;
        b2.executeForm(f1);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}