#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>

class RPN
{
private:
    std::stack<int> _stack;
    
    bool isOperator(const std::string& token) const;
    bool isValidNumber(const std::string& token) const;
    int performOperation(int a, int b, const std::string& op) const;
    void processToken(const std::string& token);

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    
    int calculate(const std::string& expression);
    
    class InvalidExpressionException : public std::exception
    {
    public:
        virtual const char* what() const throw() { return "Invalid RPN expression"; }
    };
    
    class DivisionByZeroException : public std::exception
    {
    public:
        virtual const char* what() const throw() { return "Division by zero"; }
    };
};

#endif