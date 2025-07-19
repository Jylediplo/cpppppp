#include "../headers/MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>
 
void testSubjectExample()
{
    std::cout << "=== Test de l'exemple du sujet ===" << std::endl;
    
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::stack<int> s(mstack);
    
    std::cout << std::endl;
}

void testWithList()
{
    std::cout << "=== Test avec std::list (pour comparaison) ===" << std::endl;
    
    std::list<int> mstack;
    
    mstack.push_back(5);
    mstack.push_back(17);
    
    std::cout << mstack.back() << std::endl;
    
    mstack.pop_back();
    
    std::cout << mstack.size() << std::endl;
    
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);
    
    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::cout << std::endl;
}

void testReverseIterators()
{
    std::cout << "=== Test des itérateurs inverses ===" << std::endl;
    
    MutantStack<int> mstack;
    
    for (int i = 1; i <= 5; ++i)
        mstack.push(i * 10);
    
    std::cout << "Itération normale:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    std::cout << "Itération inverse:" << std::endl;
    for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    std::cout << std::endl;
}

void testConstIterators()
{
    std::cout << "=== Test des itérateurs const ===" << std::endl;
    
    MutantStack<int> mstack;
    
    for (int i = 1; i <= 3; ++i)
        mstack.push(i * 100);
    
    const MutantStack<int>& const_mstack = mstack;
    
    std::cout << "Itération const normale:" << std::endl;
    for (MutantStack<int>::const_iterator it = const_mstack.begin(); it != const_mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    std::cout << "Itération const inverse:" << std::endl;
    for (MutantStack<int>::const_reverse_iterator it = const_mstack.rbegin(); it != const_mstack.rend(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    std::cout << std::endl;
}

void testCopyAndAssignment()
{
    std::cout << "=== Test constructeur de copie et assignation ===" << std::endl;
    
    MutantStack<int> original;
    original.push(42);
    original.push(84);
    original.push(126);
    
    // Test constructeur de copie
    MutantStack<int> copy(original);
    std::cout << "Copie - taille: " << copy.size() << ", top: " << copy.top() << std::endl;
    
    // Test opérateur d'assignation
    MutantStack<int> assigned;
    assigned = original;
    std::cout << "Assignation - taille: " << assigned.size() << ", top: " << assigned.top() << std::endl;
    
    // Vérification que les modifications sur l'original n'affectent pas les copies
    original.push(999);
    std::cout << "Après ajout à l'original:" << std::endl;
    std::cout << "Original - taille: " << original.size() << ", top: " << original.top() << std::endl;
    std::cout << "Copie - taille: " << copy.size() << ", top: " << copy.top() << std::endl;
    std::cout << "Assignation - taille: " << assigned.size() << ", top: " << assigned.top() << std::endl;
    
    std::cout << std::endl;
}

void testWithStrings()
{
    std::cout << "=== Test avec des strings ===" << std::endl;
    
    MutantStack<std::string> sstack;
    
    sstack.push("Hello");
    sstack.push("World");
    sstack.push("MutantStack");
    sstack.push("Works");
    
    std::cout << "Contenu de la stack de strings:" << std::endl;
    for (MutantStack<std::string>::iterator it = sstack.begin(); it != sstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    std::cout << std::endl;
}

void testEmptyStack()
{
    std::cout << "=== Test stack vide ===" << std::endl;
    
    MutantStack<int> empty_stack;
    
    std::cout << "Stack vide - taille: " << empty_stack.size() << std::endl;
    std::cout << "begin() == end(): " << (empty_stack.begin() == empty_stack.end() ? "true" : "false") << std::endl;
    
    std::cout << std::endl;
}

int main()
{
    std::cout << "==================== TESTS MUTANTSTACK ====================" << std::endl;
    
    testSubjectExample();
    testWithList();
    testReverseIterators();
    testConstIterators();
    testCopyAndAssignment();
    testWithStrings();
    testEmptyStack();
    
    std::cout << "================ TOUS LES TESTS TERMINÉS ================" << std::endl;
    
    return 0;
}

// // MutantStack<int> mstack;
//     std::list<int> mstack;
// mstack.push_back(5);
// mstack.push_back(17);
// std::cout << mstack.back() << std::endl;
// mstack.pop_back();
// std::cout << mstack.size() << std::endl;
// mstack.push_back(3);
// mstack.push_back(5);
// mstack.push_back(737);
// //[...]
// mstack.push_back(0);
// std::list<int>::iterator it = mstack.begin();
// std::list<int>::iterator ite = mstack.end();
// ++it;
// --it;
// while (it != ite)
// {
// std::cout << *it << std::endl;
// ++it;
// }
// // std::stack<int> s(mstack);
//     return 0;