#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "../headers/AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    RobotomyRequestForm(const std::string &target);
    virtual ~RobotomyRequestForm();
    virtual void execute(const Bureaucrat &executor) const;

private:
    std::string _target;
};

#endif