#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "../headers/AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    PresidentialPardonForm(const std::string &target);
    virtual ~PresidentialPardonForm();
    virtual void execute(const Bureaucrat &executor) const;

private:
    std::string _target;
};

#endif