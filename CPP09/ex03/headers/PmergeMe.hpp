#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <sys/time.h>
#include <iomanip>
#include <cstdlib>
#include <cctype>

class PmergeMe {
private:
    std::vector<int> _vectorData;
    std::deque<int> _dequeData;
    
    // Jacobsthal numbers generator
    static std::vector<size_t> generateJacobsthalSequence(size_t n);
    
    // Vector implementation
    static void mergeInsertSortVector(std::vector<int>& arr);
    static std::vector<std::pair<int, int> > createPairsVector(const std::vector<int>& arr);
    static void sortPairsVector(std::vector<std::pair<int, int> >& pairs);
    static void insertionSortVector(std::vector<int>& mainChain, const std::vector<int>& pendingElements);
    static int binarySearchVector(const std::vector<int>& arr, int value, int end);
    
    // Deque implementation
    static void mergeInsertSortDeque(std::deque<int>& arr);
    static std::deque<std::pair<int, int> > createPairsDeque(const std::deque<int>& arr);
    static void sortPairsDeque(std::deque<std::pair<int, int> >& pairs);
    static void insertionSortDeque(std::deque<int>& mainChain, const std::deque<int>& pendingElements);
    static int binarySearchDeque(const std::deque<int>& arr, int value, int end);
    
    // Utility functions
    static bool isValidNumber(const std::string& str);
    static void printSequence(const std::vector<int>& arr, const std::string& prefix);
    
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    
    void parseInput(int argc, char** argv);
    void sortAndTime();
};

#endif