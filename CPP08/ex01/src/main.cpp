#include "../headers/Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

void testBasicFunctionality()
{
    std::cout << "=== Test de base (exemple du sujet) ===" << std::endl;
    
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
    std::cout << "=== Test des exceptions ===" << std::endl;
    
    // Test exception span plein
    try
    {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3); // Devrait lever une exception
    }
    catch(const Span::SpanFullException& e)
    {
        std::cout << "Exception attendue: " << e.what() << std::endl;
    }
    
    // Test exception pas assez de nombres pour shortestSpan
    try
    {
        Span sp(5);
        sp.addNumber(42);
        sp.shortestSpan(); // Devrait lever une exception
    }
    catch(const Span::NoSpanFoundException& e)
    {
        std::cout << "Exception attendue: " << e.what() << std::endl;
    }
    
    // Test exception pas assez de nombres pour longestSpan
    try
    {
        Span sp(5);
        sp.longestSpan(); // Devrait lever une exception (aucun nombre)
    }
    catch(const Span::NoSpanFoundException& e)
    {
        std::cout << "Exception attendue: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

void testLargeNumbers()
{
    std::cout << "=== Test avec 10 000 nombres ===" << std::endl;
    
    Span sp(10000);
    
    // Remplissage avec des nombres aléatoires
    srand(time(NULL));
    for (int i = 0; i < 10000; ++i)
    {
        sp.addNumber(rand() % 100000);
    }
    
    std::cout << "Span rempli avec " << sp.size() << " nombres" << std::endl;
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    std::cout << std::endl;
}

void testIteratorRange()
{
    std::cout << "=== Test avec plage d'itérateurs ===" << std::endl;
    
    // Test avec vector
    std::vector<int> vec;
    for (int i = 0; i < 1000; ++i)
    {
        vec.push_back(i * 2);
    }
    
    Span sp1(1000);
    sp1.addNumbers(vec.begin(), vec.end());
    
    std::cout << "Span rempli avec vector (" << sp1.size() << " éléments)" << std::endl;
    std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp1.longestSpan() << std::endl;
    
    // Test avec list
    std::list<int> lst;
    for (int i = 100; i >= 1; --i)
    {
        lst.push_back(i * 3);
    }
    
    Span sp2(100);
    sp2.addNumbers(lst.begin(), lst.end());
    
    std::cout << "Span rempli avec list (" << sp2.size() << " éléments)" << std::endl;
    std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    
    // Test exception avec trop d'éléments
    try
    {
        Span sp3(50);
        sp3.addNumbers(vec.begin(), vec.end()); // Trop d'éléments
    }
    catch(const Span::SpanFullException& e)
    {
        std::cout << "Exception attendue lors de l'ajout en masse: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

void testCopyConstructorAndAssignment()
{
    std::cout << "=== Test constructeur de copie et assignation ===" << std::endl;
    
    Span sp1(5);
    sp1.addNumber(10);
    sp1.addNumber(20);
    sp1.addNumber(30);
    
    // Test constructeur de copie
    Span sp2(sp1);
    std::cout << "Copie - Size: " << sp2.size() << ", Shortest: " << sp2.shortestSpan() << std::endl;
    
    // Test opérateur d'assignation
    Span sp3(10);
    sp3 = sp1;
    std::cout << "Assignation - Size: " << sp3.size() << ", Shortest: " << sp3.shortestSpan() << std::endl;
    
    std::cout << std::endl;
}

void testEdgeCases()
{
    std::cout << "=== Test cas limites ===" << std::endl;
    
    // Test avec deux nombres identiques
    Span sp1(3);
    sp1.addNumber(5);
    sp1.addNumber(5);
    sp1.addNumber(10);
    std::cout << "Nombres identiques - Shortest: " << sp1.shortestSpan() << std::endl;
    std::cout << "Nombres identiques - Longest: " << sp1.longestSpan() << std::endl;
    
    // Test avec nombres négatifs
    Span sp2(4);
    sp2.addNumber(-100);
    sp2.addNumber(-50);
    sp2.addNumber(0);
    sp2.addNumber(50);
    std::cout << "Nombres négatifs - Shortest: " << sp2.shortestSpan() << std::endl;
    std::cout << "Nombres négatifs - Longest: " << sp2.longestSpan() << std::endl;
    
    // Test avec span de taille 0
    try
    {
        Span sp3(0);
        sp3.addNumber(1); // Devrait lever une exception
    }
    catch(const Span::SpanFullException& e)
    {
        std::cout << "Exception attendue pour span de taille 0: " << e.what() << std::endl;
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
    
    std::cout << "================ TOUS LES TESTS TERMINÉS ================" << std::endl;
    
    return 0;
}