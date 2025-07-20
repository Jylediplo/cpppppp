#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

class Span
{
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

    template<typename Iterator>
    void addNumbers(Iterator begin, Iterator end);

    unsigned int size() const;
    unsigned int maxSize() const;

    class SpanFullException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    class NoSpanFoundException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};

template<typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
    while (begin != end)
    {
        if (_numbers.size() >= _maxSize)
            throw SpanFullException();
        _numbers.push_back(*begin);
        ++begin;
    }
}

#endif