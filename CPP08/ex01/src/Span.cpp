#include "../headers/Span.hpp"

// Constructeur par défaut
Span::Span() : _maxSize(0)
{
}

// Constructeur avec paramètre
Span::Span(unsigned int N) : _maxSize(N)
{
}

// Constructeur de copie
Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

// Opérateur d'assignation
Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

// Destructeur
Span::~Span()
{
}

// Ajouter un nombre
void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw SpanFullException();
    _numbers.push_back(number);
}

// Trouver la plus petite distance
int Span::shortestSpan() const
{
    if (_numbers.size() <= 1)
        throw NoSpanFoundException();

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 2; i < sorted.size(); ++i)
    {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

// Trouver la plus grande distance
int Span::longestSpan() const
{
    if (_numbers.size() <= 1)
        throw NoSpanFoundException();

    std::vector<int>::const_iterator min = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator max = std::max_element(_numbers.begin(), _numbers.end());
    
    return *max - *min;
}

// Obtenir la taille actuelle
unsigned int Span::size() const
{
    return _numbers.size();
}

// Obtenir la taille maximale
unsigned int Span::maxSize() const
{
    return _maxSize;
}

// Implémentation des exceptions
const char* Span::SpanFullException::what() const throw()
{
    return "Span is full, cannot add more numbers";
}

const char* Span::NoSpanFoundException::what() const throw()
{
    return "No span can be found (need at least 2 numbers)";
}