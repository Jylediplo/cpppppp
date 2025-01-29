#include "../headers/Harl.hpp"

int main(void)
{
    Harl harl;
    harl.complain("INF");
    harl.complain("ERROR");
    harl.complain("WARNING");
    harl.complain("");
    harl.complain("DEBUG");
    harl.complain("INFO");
    return (0);
}