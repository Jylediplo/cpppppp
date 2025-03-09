#include "../headers/ScalarConverter.hpp"

bool isChar(const std::string &str)
{
    return str.length() == 1 && !isdigit(str[0]);
}

bool isInt(const std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (i == 0 && (str[i] == '-' || str[i] == '+'))
            continue;
        if (!isdigit(str[i])) return false;
    }
    return true;
}

bool isFloat(const std::string &str)
{
    return str.find('f') != std::string::npos;
}

bool isDouble(const std::string &str)
{
    return str.find('.') != std::string::npos && str.find('f') == std::string::npos;
}

void printChar(char c)
{
    if (isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }

    if (literal == "+inf" || literal == "+inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return;
    }

    if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }

    if (isChar(literal))
    {
        char c = literal[0];
        printChar(c);
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }

    try {
        double num = std::strtod(literal.c_str(), NULL);

        if (num < std::numeric_limits<char>::min() || num > std::numeric_limits<char>::max())
            std::cout << "char: impossible" << std::endl;
        else
            printChar(static_cast<char>(num));

        if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(num) << std::endl;
        std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
        std::cout << "double: " << num << ".0" << std::endl;
    } catch (const std::exception &)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}
