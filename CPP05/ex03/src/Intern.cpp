#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
   return (*this);
}

Intern::~Intern() {}

AForm* Intern::createShrubberyCreationForm(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

const Intern::FormType Intern::formTypes[3] =
{
    {"shrubbery creation", &Intern::createShrubberyCreationForm},
    {"robotomy request", &Intern::createRobotomyRequestForm},
    {"presidential pardon", &Intern::createPresidentialPardonForm}
};

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    for (int i = 0; i < 3; i++)
    {
        if (formName == formTypes[i].name)
        {
            AForm* form = (this->*(formTypes[i].creator))(target);
            std::cout << "Intern creates " << formName << std::endl;
            return form;
        }
    }
    std::cerr << "Error: Form name '" << formName << "' is invalid." << std::endl;
    return NULL;
}