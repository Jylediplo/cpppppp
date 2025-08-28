#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

class BitcoinExchange
{
private:
    std::map<std::string, double> _database;
    
    void loadDatabase();
    bool isValidDate(const std::string& date) const;
    bool isValidValue(const std::string& valueStr, double& value) const;
    std::string trim(const std::string& str) const;
    double findClosestRate(const std::string& date) const;
    bool isBisextileYear(int year) const;
    bool isDateBefore(const std::string& date1, const std::string& date2) const;
    void processLine(const std::string& line) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    
    void processInputFile(const std::string& filename);
    
    class DatabaseException : public std::exception
    {
    public:
        virtual const char* what() const throw() { return "could not load database"; }
    };
    
    class FileException : public std::exception
    {
    public:
        virtual const char* what() const throw() { return "could not open file."; }
    };
};

#endif