#include "../headers/whatever.hpp"

int main(void)
{
    int a = 2; 
    int b = 3;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    int y = 2;
    int z = 2;
    std::cout << "addy y : " << &y << std::endl;
    std::cout << "addy z : " << &z << std::endl;
    std::cout << "min(2 == 2) = " << &(::max(y,z)) << std::endl;
    return 0;
}
