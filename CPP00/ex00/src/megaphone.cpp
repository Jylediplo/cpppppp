#include <iostream>

int main(int argc, char **argv)
{
    std::string input;
    char c;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int j = 1; j < argc; j++)
    {
        input = argv[j];
        for(std::size_t i = 0; i < input.length(); i++)
        {
            c = toupper(input[i]);
            std::cout << c;
        }
    }
	std::cout << std::endl;
    return (0);
}