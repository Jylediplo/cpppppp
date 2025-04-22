 #include "../headers/Intern.hpp"
#include "../headers/AForm.hpp"

#include <iostream>
#include <exception>

#include <iostream>
#include <exception>

#define RUN(code, errorMessage)             \
    try                                     \
    {                                       \
        code;                               \
    }                                       \
    catch (const std::exception &e)         \
    {                                       \
        std::cerr << errorMessage << ": " << e.what() << std::endl; \
    }

int main() {
    Intern intern;
    AForm* form;

    Bureaucrat highRank("Alice", 1); 
    Bureaucrat midRank("Bob", 50);   
    Bureaucrat lowRank("Charlie", 150); 

    std::cout << "\n===== Testing Form Creation =====\n";
    RUN(
        form = intern.makeForm("robotomy request", "Bender");
        if (form) delete form;,
        "Form Creation (robotomy request) Error"
    );

    RUN(
        form = intern.makeForm("shrubbery creation", "Home");
        if (form) delete form;,
        "Form Creation (shrubbery creation) Error"
    );

    RUN(
        form = intern.makeForm("presidential pardon", "Alice");
        if (form) delete form;,
        "Form Creation (presidential pardon) Error"
    );

    RUN(
        form = intern.makeForm("invalid form", "Target");
        if (form) delete form;,
        "Form Creation (invalid form) Error"
    );

    std::cout << "\n===== Signing and Executing Forms with Different Bureaucrats =====\n";

    RUN(
        form = intern.makeForm("shrubbery creation", "Park");
        if (form)
        {
            std::cout << "\n-> Signing with Mid-Level Bureaucrat (Bob, Grade 50)\n";
            midRank.signForm(*form);

            std::cout << "\n-> Attempting to Execute with Low-Level Bureaucrat (Charlie, Grade 150)\n";
            lowRank.executeForm(*form); 

            std::cout << "\n-> Executing with Mid-Level Bureaucrat (Bob, Grade 50)\n";
            midRank.executeForm(*form);

            delete form;
        };,
        "Shrubbery Form Signing/Execution Error"
    );

    RUN(
        form = intern.makeForm("robotomy request", "Bender");
        if (form)
        {
            std::cout << "\n-> Signing with High-Rank Bureaucrat (Alice, Grade 1)\n";
            highRank.signForm(*form);

            std::cout << "\n-> Attempting Execution with Mid-Level Bureaucrat (Bob, Grade 50)\n";
            midRank.executeForm(*form);

            delete form;
        };,
        "Robotomy Form Signing/Execution Error"
    );

    RUN(
        form = intern.makeForm("presidential pardon", "Alice");
        if (form)
        {
            std::cout << "\n-> Attempting Execution Without Signing (Bob, Grade 50)\n";
            midRank.executeForm(*form);

            std::cout << "\n-> Signing with High-Rank Bureaucrat (Alice, Grade 1)\n";
            highRank.signForm(*form);

            std::cout << "\n-> Attempting Execution with Mid-Level Bureaucrat (Bob, Grade 50)\n";
            midRank.executeForm(*form);

            std::cout << "\n-> Executing with High-Rank Bureaucrat (Alice, Grade 1)\n";
            highRank.executeForm(*form);

            delete form;
        };,
        "Presidential Pardon Form Signing/Execution Error"
    );

    return 0;
}
