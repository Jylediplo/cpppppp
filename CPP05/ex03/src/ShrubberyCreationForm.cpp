#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("Unknown") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    checkExecutionRequirements(executor);

    std::ofstream file((_target + "_shrubbery").c_str());
    if (file.is_open())
    {
        file << "  ^  \n"
             << " ^^^ \n"
             << "^^^^^\n"
             << "  |  \n";
        file.close();
    }
    else
    {
        std::cerr << "Error: Could not create file." << std::endl;
    }
}