#include "../headers/Bureaucrat.hpp"
#include "../headers/Form.hpp"


#define RUN(code, errorMessage)    \
    try                                     \
    {                                       \
        code;                               \
    }                                       \
    catch (const std::exception &e)         \
    {                                       \
        std::cerr << errorMessage << ": " << e.what() << std::endl; \
    }

int main()
{
    try
    {
        RUN(Bureaucrat b1("tom", 1); std::cout << b1 << std::endl;, "Bureaucrat b1 Error");
        RUN(Bureaucrat b2("tibo", 149); std::cout << b2 << std::endl;, "Bureaucrat b2 Error");

        RUN(Form f1("One Form", 1, 1); std::cout << f1 << std::endl;, "Form f1 Error");
        RUN(Form f2("Other Form", 150, 140); std::cout << f2 << std::endl;, "Form f2 Error");

        RUN(Form f3("Invalid Form", 0, 151); std::cout << f3 << std::endl;, "Form f3 Error");
        RUN(Form f4("Invalid Again", 0, 0); std::cout << f4 << std::endl;, "Form f4 Error");

        RUN(
            Bureaucrat b1("tom", 140);
            Form f1("One Form", 139, 139);
            b1.signForm(f1);
            std::cout << f1 << std::endl;, 
            "Signing f1 Error"
        );

        RUN(
            Bureaucrat b2("tibo", 149);
            Form f2("Other Form", 150, 140);
            b2.signForm(f2);
            std::cout << f2 << std::endl;, 
            "Signing f2 Error"
        );
    }
    catch (const std::exception &e)
    {
        std::cerr << "Unexpected Error: " << e.what() << std::endl;
    }

    return 0;
}
