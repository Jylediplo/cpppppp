#include "../headers/RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib> 
#include <ctime>  

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    checkExecutionRequirements(executor);

    std::cout << "Drilling noises... Brrrrrrrrrrrrrr!" << std::endl;
    std::srand(std::time(0));

    if (std::rand() % 2 == 0)
    {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy failed for " << _target << "." << std::endl;
    }
}