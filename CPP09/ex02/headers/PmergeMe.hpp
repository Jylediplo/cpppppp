#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <stdexcept>

class PmergeMe
{
private:
    std::vector<int> _vectorData;
    std::deque<int> _dequeData;
    
    // Ford-Johnson algorithm for vector
    void fordJohnsonVector(std::vector<int>& arr);
    void insertionSortVector(std::vector<int>& arr, int left, int right);
    void mergeVector(std::vector<int>& arr, int left, int mid, int right);
    
    // Ford-Johnson algorithm for deque
    void fordJohnsonDeque(std::deque<int>& arr);
    void insertionSortDeque(std::deque<int>& arr, int left, int right);
    void mergeDeque(std::deque<int>& arr, int left, int mid, int right);
    
    // Utility functions
    void printSequence(const std::vector<int>& arr, const std::string& prefix) const;
    double getTime() const;

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    
    void addNumber(int num);
    void sort();
    
    class InvalidInputException : public std::exception
    {
    public:
        virtual const char* what() const throw() { return "Invalid input"; }
    };
};

#endif