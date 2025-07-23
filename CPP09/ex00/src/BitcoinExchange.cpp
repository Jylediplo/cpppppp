#include "../headers/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    loadDatabase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        _database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadDatabase()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw DatabaseException();
    
    std::string line;
    std::getline(file, line);
    
    while (std::getline(file, line))
    {
        size_t pos = line.find(',');
        if (pos != std::string::npos)
        {
            std::string date = line.substr(0, pos);
            std::string rateStr = line.substr(pos + 1);
            
            double rate = std::atof(rateStr.c_str());
            _database[date] = rate;
        }
    }
    file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    
    for (size_t i = 0; i < date.length(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }
    
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    
    if (year < 1000 || year > 9999)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    
    if (month == 2 && day > 29)
        return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, double& value) const
{
    if (valueStr.empty())
        return false;
    
    char* endptr;
    value = std::strtod(valueStr.c_str(), &endptr);
    
    if (*endptr != '\0')
        return false;
    
    return value >= 0 && value <= 1000;
}

std::string BitcoinExchange::trim(const std::string& str) const
{
    size_t start = str.find_first_not_of(" \t");
    if (start == std::string::npos)
        return "";
    
    size_t end = str.find_last_not_of(" \t");
    return str.substr(start, end - start + 1);
}

double BitcoinExchange::findClosestRate(const std::string& date) const
{
    std::map<std::string, double>::const_iterator it = _database.lower_bound(date);
    
    if (it != _database.begin())
        --it;
    else if (it == _database.end() || it->first != date)
        return -1; // No previous date found
    // std::cout << "test : " << (++it)->first << "date : " << date << std::endl;
    if ((++it)->first == date)
        return (it)->second;
    return it->second;
}

// bool BitcoinExchange::isDateBefore(const std::string& date1, const std::string& date2) const
// {
//     return date1 < date2;
// }

void BitcoinExchange::processLine(const std::string& line) const
{
    if (line.empty())
        return;
    
    size_t pos = line.find(" | ");
    if (pos == std::string::npos)
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return;
    }
    
    std::string dateStr = trim(line.substr(0, pos));
    std::string valueStr = trim(line.substr(pos + 3));
    
    if (!isValidDate(dateStr))
    {
        std::cout << "Error: bad input => " << dateStr << std::endl;
        return;
    }
    
    double value;
    if (!isValidValue(valueStr, value))
    {
        if (value < 0)
            std::cout << "Error: not a positive number." << std::endl;
        else if (value > 1000)
            std::cout << "Error: too large a number." << std::endl;
        else
            std::cout << "Error: bad input => " << valueStr << std::endl;
        return;
    }
    
    double rate = findClosestRate(dateStr);
    if (rate < 0)
    {
        std::cout << "Error: bad input => " << dateStr << std::endl;
        return;
    }
    
    double result = value * rate;
    std::cout << dateStr << " => " << value << " = " << result << std::endl;
}

void BitcoinExchange::processInputFile(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw FileException();
    
    std::string line;
    std::getline(file, line);
    
    while (std::getline(file, line))
    {
        processLine(line);
    }
    
    file.close();
}