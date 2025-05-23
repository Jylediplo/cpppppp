 #include "../headers/main.hpp"

int replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2)
{
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return (0);
    }

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Could not create output file " << filename + ".replace" << std::endl;
        inputFile.close();
        return (0);
    }
    std::string line;
    while (std::getline(inputFile, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length(); 
        }
        outputFile << line << std::endl;
    }
    inputFile.close();
    outputFile.close();
    return (1);
}

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return (1);
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (s1.empty())
    {
        std::cerr << "Error: s1 cannot be an empty string." << std::endl;
        return (1);
    }
    if (!replaceInFile(filename, s1, s2))
        return (1);
    std::cout << "Replacement complete. Check " << filename << ".replace" << std::endl;
    return (0);
}