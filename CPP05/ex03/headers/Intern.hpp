#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern {
public:
    Intern();
    ~Intern();
    AForm* makeForm(const std::string& formName, const std::string& target);

private:
    AForm* createShrubberyCreationForm(const std::string& target);
    AForm* createRobotomyRequestForm(const std::string& target);
    AForm* createPresidentialPardonForm(const std::string& target);

    typedef AForm* (Intern::*FormCreator)(const std::string&);
    struct FormType {
        std::string name;
        FormCreator creator;
    };
    static const FormType formTypes[3];
};

#endif