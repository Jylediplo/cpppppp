#include "../headers/Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

void testBasicFunctionality()
{
    std::cout << "=== subject test ===" << std::endl;
    
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    std::cout << std::endl;
}

void testExceptions()
{
    std::cout << "=== Test with exceptions ===" << std::endl;
    
    try
    {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
    }
    catch(const Span::SpanFullException& e)
    {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }
    
    try
    {
        Span sp(5);
        sp.addNumber(42);
        sp.shortestSpan();
    }
    catch(const Span::NoSpanFoundException& e)
    {
        std::cout << "Exception expected: " << e.what() << std::endl;
    }
    
    try
    {
        Span sp(5);
        sp.longestSpan();
    }
    catch(const Span::NoSpanFoundException& e)
    {
        std::cout << "Exception expected: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

void testLargeNumbers()
{
    std::cout << "=== Test with 10 000 numbers ===" << std::endl;
    
    Span sp(10000);
    
    srand(time(NULL));
    for (int i = 0; i < 10000; ++i)
    {
        sp.addNumber(rand() % 100000);
    }
    
    std::cout << "Span filled with " << sp.size() << " numbers" << std::endl;
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    std::cout << std::endl;
}

void testIteratorRange()
{
    std::cout << "=== iterator range test ===" << std::endl;
    
    std::vector<int> vec;
    for (int i = 0; i < 1000; ++i)
    {
        vec.push_back(i * 2);
    }
    
    Span sp1(1000);
    sp1.addNumbers(vec.begin(), vec.end());
    
    std::cout << "Span filled with vector (" << sp1.size() << " elements)" << std::endl;
    std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp1.longestSpan() << std::endl;
    
    std::list<int> lst;
    for (int i = 100; i >= 1; --i)
    {
        lst.push_back(i * 3);
    }
    
    Span sp2(100);
    sp2.addNumbers(lst.begin(), lst.end());
    
    std::cout << "Span filled with list (" << sp2.size() << " elements)" << std::endl;
    std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    
    try
    {
        Span sp3(50);
        sp3.addNumbers(vec.begin(), vec.end());
    }
    catch(const Span::SpanFullException& e)
    {
        std::cout << "Expected exception when mass adding: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

void testCopyConstructorAndAssignment()
{
    std::cout << "=== Copy constructor and assignation test ===" << std::endl;
    
    Span sp1(5);
    sp1.addNumber(10);
    sp1.addNumber(20);
    sp1.addNumber(30);
    
    Span sp2(sp1);
    std::cout << "Copy - Size: " << sp2.size() << ", Shortest: " << sp2.shortestSpan() << std::endl;
    
    Span sp3(10);
    sp3 = sp1;
    std::cout << "Assignation - Size: " << sp3.size() << ", Shortest: " << sp3.shortestSpan() << std::endl;
    
    std::cout << std::endl;
}

void testEdgeCases()
{
    std::cout << "=== limits cases ===" << std::endl;
    
    Span sp1(3);
    sp1.addNumber(5);
    sp1.addNumber(5);
    sp1.addNumber(10);
    std::cout << "Same numbers - Shortest: " << sp1.shortestSpan() << std::endl;
    std::cout << "Same numbers - Longest: " << sp1.longestSpan() << std::endl;
    
    Span sp2(4);
    sp2.addNumber(-100);
    sp2.addNumber(-50);
    sp2.addNumber(0);
    sp2.addNumber(50);
    std::cout << "Negative numbers - Shortest: " << sp2.shortestSpan() << std::endl;
    std::cout << "Negative numbers - Longest: " << sp2.longestSpan() << std::endl;
    
    try
    {
        Span sp3(0);
        sp3.addNumber(1);
    }
    catch(const Span::SpanFullException& e)
    {
        std::cout << "Expected exception for span of size 0: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "==================== TESTS SPAN ====================" << std::endl;
    
    testBasicFunctionality();
    testExceptions();
    testLargeNumbers();
    testIteratorRange();
    testCopyConstructorAndAssignment();
    testEdgeCases();
    
    std::cout << "================ Tests done ================" << std::endl;
    
    return 0;
}