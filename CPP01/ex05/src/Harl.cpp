#include "../headers/Harl.hpp"

void Harl::debug( void )
{
    std::cout << "DEBUG" << std::endl;
}

void Harl::info( void )
{
    std::cout << "INFO" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "WARNING" << std::endl;
}

void Harl::error( void )
{
    std::cout << "ERROR" << std::endl;
}

void Harl::complain( std::string level )
{
    std::map<std::string, void (Harl::*)()> messages;
    messages["DEBUG"] = &Harl::debug;
    messages["INFO"] = &Harl::info;
    messages["WARNING"] = &Harl::warning;
    messages["ERROR"] = &Harl::error;

    if (!messages.count(level))
        std::cout << "unknown messages !" << std::endl;
    else
        (this->*(messages[level]))();
}

