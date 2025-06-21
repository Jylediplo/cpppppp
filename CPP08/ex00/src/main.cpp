#include "../headers/easyfind.hpp"

const char * NoOccurenceException::what() const throw()
{
    return "No matching numbers found";
}

int main(void)
{
    std::vector<int> vec;
    std::list<int> lst;

    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(3);
    vec.push_back(2);

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    try {
        easyfind(vec, 3);   // trouvé
        easyfind(vec, 9);   // pas trouvé
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        easyfind(lst, 20);  // trouvé
        easyfind(lst, 99);  // pas trouvé
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}