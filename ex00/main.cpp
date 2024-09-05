#include <iostream>

int main(int argc, char **argv)
{
    std::string input;
    char c;

    input = argv[1];
    for(int i = 0; i < input.length(); i++)
    {
        c = toupper(input[i]);
        std::cout << c;
    }
    return (0);
}