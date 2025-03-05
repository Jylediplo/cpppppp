#include "../headers/Intern.hpp"
#include "../headers/AForm.hpp"

int main() {
    Intern intern;
    AForm* form;

    form = intern.makeForm("robotomy request", "Bender");
    if (form)
    {
        delete form;
    }

    form = intern.makeForm("shrubbery creation", "Home");
    if (form)
    {
        delete form;
    }

    form = intern.makeForm("presidential pardon", "Alice");
    if (form)
    {
        std::cout << form->getName() << std::endl;
        delete form;
    }

    form = intern.makeForm("invalid form", "Target");
    if (form)
    {
        delete form;
    }

    form = intern.makeForm("robotomy request", "Bender");
    if (form)
        delete form;
    return 0;
}