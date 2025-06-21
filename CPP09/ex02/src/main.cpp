#include "../headers/PmergeMe.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    try
    {
        PmergeMe sorter;
        
        // Parse and validate input
        for (int i = 1; i < argc; ++i)
        {
            char* endptr;
            long num = std::strtol(argv[i], &endptr, 10);
            
            if (*endptr != '\0' || num < 0 || num > 2147483647)
            {
                std::cerr << "Error" << std::endl;
                return 1;
            }
            
            sorter.addNumber(static_cast<int>(num));
        }
        
        sorter.sort();
        
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    return 0;
}