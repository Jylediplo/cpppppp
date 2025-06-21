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
    // Constructeurs et destructeur (forme canonique de Coplien)
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    // Fonctions membres principales
    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

    // Fonction pour ajouter une plage d'itérateurs
    template<typename Iterator>
    void addNumbers(Iterator begin, Iterator end);

    // Fonctions utilitaires
    unsigned int size() const;
    unsigned int maxSize() const;

    // Classes d'exception
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

// Implémentation de la fonction template dans le header
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