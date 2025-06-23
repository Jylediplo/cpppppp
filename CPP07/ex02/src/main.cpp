#include "../headers/Array.hpp"

int main()
{
    Array<int> u;
    std::cout << "u.size() = " << u.size() << std::endl;

    Array<int> a(5);
    std::cout << "a.size() = " << a.size() << std::endl;

    for (unsigned int i = 0; i < a.size(); ++i)
        a[i] = i * 10;

    for (unsigned int i = 0; i < a.size(); ++i)
        std::cout << "a[" << i << "] = " << a[i] << std::endl;

    try {
        std::cout << "Access out of bounds : " << a[10] << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    Array<int> b = a;
    b[0] = 42;

    std::cout << "After copy and modification of b :" << std::endl;
    std::cout << "a[0] = " << a[0] << ", b[0] = " << b[0] << std::endl;

    Array<int> c;
    c = a;
    c[1] = 99;
    std::cout << "aFTER affectation and modification of c :" << std::endl;
    std::cout << "a[1] = " << a[1] << ", c[1] = " << c[1] << std::endl;

    return 0;
}
