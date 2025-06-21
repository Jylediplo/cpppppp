#include "../headers/Array.hpp"

int main()
{
    Array<int> u;
    Array<int> a(5);

    for (unsigned int i = 0; i < a.size(); ++i)
        a[i] = i * 10;

    for (unsigned int i = 0; i < a.size(); ++i)
        std::cout << a[i] << std::endl;

    try {
        std::cout << a[10] << std::endl; // doit throw
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    Array<int> b = a;
    b[0] = 42;
    std::cout << "a[0] = " << a[0] << ", b[0] = " << b[0] << std::endl;

    return 0;
}
