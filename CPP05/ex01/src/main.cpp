#include "../headers/Bureaucrat.hpp"
#include "../headers/Form.hpp"

int main()
{
    try
    {
        Bureaucrat b1("John", 1);
        Bureaucrat b2("Doe", 150);

        Form f1("Tax Form", 1, 1);
        Form f2("Application Form", 150, 150);

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

        b1.signForm(f1);
        b2.signForm(f2);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

        Form f3("Invalid Form", 0, 151);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}