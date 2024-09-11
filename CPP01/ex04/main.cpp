#include "main.hpp"

void handle_input(std::string file, std::string s1, std::string s2)
{;
	std::string out;
	(void)s1;
	(void)s2;

	
	std::ofstream myfile;
  	myfile.open (file.c_str());
	myfile << "Writing this to a file.\n";
  	myfile.close();
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "wrong numbers of arguments !" << std::endl;
        return (1);
    }
    std::string file = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    handle_input(file, s1, s2);
    return (0);
}