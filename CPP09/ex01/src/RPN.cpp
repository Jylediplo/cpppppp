#include "../headers/RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& other) : _stack(other._stack)
{
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
    {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN()
{
}

bool RPN::isOperator(const std::string& token) const
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isValidNumber(const std::string& token) const
{
    if (token.empty())
        return false;
    
    // Check if it's a single digit (0-9)
    if (token.length() == 1 && std::isdigit(token[0]))
        return true;
    
    return false;
}

int RPN::performOperation(int a, int b, const std::string& op) const
{
    if (op == "+")
        return a + b;
    else if (op == "-")
        return a - b;
    else if (op == "*")
        return a * b;
    else if (op == "/")
    {
        if (b == 0)
            throw DivisionByZeroException();
        return a / b;
    }
    throw InvalidExpressionException();
}

void RPN::processToken(const std::string& token)
{
    if (isValidNumber(token))
    {
        int num = token[0] - '0';
        _stack.push(num);
    }
    else if (isOperator(token))
    {
        if (_stack.size() < 2)
            throw InvalidExpressionException();
        
        int b = _stack.top();
        _stack.pop();
        int a = _stack.top();
        _stack.pop();
        
        int result = performOperation(a, b, token);
        _stack.push(result);
    }
    else
    {
        throw InvalidExpressionException();
    }
}

int RPN::calculate(const std::string& expression)
{
    // Clear stack for new calculation
    while (!_stack.empty())
        _stack.pop();
    
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token)
    {
        processToken(token);
    }
    
    if (_stack.size() != 1)
        throw InvalidExpressionException();
    
    return _stack.top();
}