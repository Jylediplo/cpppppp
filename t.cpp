#include <iostream>
 
int main(void) 
{
	std::cout << "enter value ";
	int str;

	std::cin >> str;

	if (!std::cin)
		printf("not a number");
	std::cout << std::endl << "str : " << str << std::endl;
	// if (std::stoi(str) == 1)
	// 	std::cout << "bien egal à 1"; 
	return(0);

