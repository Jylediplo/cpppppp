#include "../headers/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vectorData(other._vectorData), _dequeData(other._dequeData) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
    }
    return *this;
}

bool PmergeMe::isValidNumber(const std::string& str) {
    if (str.empty()) return false;
    
    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isdigit(str[i])) return false;
    }
    
    // Check for overflow
    std::istringstream iss(str);
    long long num;
    iss >> num;
    
    return num >= 0 && num <= 2147483647;
}

void PmergeMe::parseInput(int argc, char** argv)
{
    if (argc < 2)
        throw std::runtime_error("Error: No arguments provided");
    
    for (int i = 1; i < argc; ++i)
    {
        if (!isValidNumber(argv[i]))
            throw std::runtime_error("Error: Invalid number format");
        
        int num = std::atoi(argv[i]);
        if (num < 0)
            throw std::runtime_error("Error: Negative numbers not allowed");
        
        _vectorData.push_back(num);
        _dequeData.push_back(num);
    }
}

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n)
{
    std::vector<size_t> jacobsthal;
    if (n == 0)
        return jacobsthal;
    
    jacobsthal.push_back(1);
    if (n == 1)
        return jacobsthal;
    
    jacobsthal.push_back(1);
    
    for (size_t i = 2; i < n; ++i)
    {
        size_t next = jacobsthal[i-1] + 2 * jacobsthal[i-2];
        if (next > n)
            break;
        jacobsthal.push_back(next);
    }
    
    return jacobsthal;
}

// Vector implementation
std::vector<std::pair<int, int> > PmergeMe::createPairsVector(const std::vector<int>& arr)
{
    std::vector<std::pair<int, int> > pairs;
    
    for (size_t i = 0; i + 1 < arr.size(); i += 2)
    {
        if (arr[i] > arr[i + 1])
        {
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        } else
        {
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        }
    }
    
    return pairs;
}


void PmergeMe::sortPairsVector(std::vector<std::pair<int, int> >& pairs)
{
    if (pairs.size() <= 1)
        return;
    
    for (size_t i = 1; i < pairs.size(); ++i)
    {
        std::pair<int, int> key = pairs[i];
        int j = i - 1;
        
        while (j >= 0 && pairs[j].first > key.first)
        {
            pairs[j + 1] = pairs[j];
            j--;
        }
        pairs[j + 1] = key;
    }
}

int PmergeMe::binarySearchVector(const std::vector<int>& arr, int value, int end) {
    int left = 0, right = end;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}

void PmergeMe::insertionSortVector(std::vector<int>& mainChain, const std::vector<int>& pendingElements) {
    if (pendingElements.empty())
        return;
    
    std::vector<size_t> jacobsthal = generateJacobsthalSequence(pendingElements.size());
    std::vector<bool> inserted(pendingElements.size(), false);
    
    // Insert elements using Jacobsthal sequence
    for (size_t i = 0; i < jacobsthal.size(); ++i) {
        size_t idx = jacobsthal[i] - 1;
        if (idx < pendingElements.size() && !inserted[idx]) {
            int pos = binarySearchVector(mainChain, pendingElements[idx], mainChain.size());
            mainChain.insert(mainChain.begin() + pos, pendingElements[idx]);
            inserted[idx] = true;
        }
    }
    
    // Insert remaining elements
    for (size_t i = 0; i < pendingElements.size(); ++i) {
        if (!inserted[i]) {
            int pos = binarySearchVector(mainChain, pendingElements[i], mainChain.size());
            mainChain.insert(mainChain.begin() + pos, pendingElements[i]);
        }
    }
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& arr)
{
    if (arr.size() <= 1) return;
    
    bool hasOdd = (arr.size() % 2 == 1);
    int oddElement = hasOdd ? arr.back() : 0;
    
    if (hasOdd) arr.pop_back();
    
    // Create pairs and sort them
    std::vector<std::pair<int, int> > pairs = createPairsVector(arr);
    sortPairsVector(pairs);
    
    // Create main chain and pending elements
    std::vector<int> mainChain;
    std::vector<int> pendingElements;
    
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainChain.push_back(pairs[i].first);
        pendingElements.push_back(pairs[i].second);
    }
    
    // Insert pending elements using Ford-Johnson algorithm
    insertionSortVector(mainChain, pendingElements);
    
    // Insert odd element if exists
    if (hasOdd)
    {
        int pos = binarySearchVector(mainChain, oddElement, mainChain.size());
        mainChain.insert(mainChain.begin() + pos, oddElement);
    }
    
    arr = mainChain;
}

// Deque implementation (similar structure)
std::deque<std::pair<int, int> > PmergeMe::createPairsDeque(const std::deque<int>& arr) {
    std::deque<std::pair<int, int> > pairs;
    
    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1]) {
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        } else {
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        }
    }
    
    return pairs;
}

void PmergeMe::sortPairsDeque(std::deque<std::pair<int, int> >& pairs) {
    if (pairs.size() <= 1) return;
    
    if (pairs.size() > 1) {
        std::deque<std::pair<int, int> > left(pairs.begin(), pairs.begin() + pairs.size() / 2);
        std::deque<std::pair<int, int> > right(pairs.begin() + pairs.size() / 2, pairs.end());
        
        sortPairsDeque(left);
        sortPairsDeque(right);
        
        // Merge
        size_t i = 0, j = 0, k = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i].first <= right[j].first) {
                pairs[k++] = left[i++];
            } else {
                pairs[k++] = right[j++];
            }
        }
        
        while (i < left.size()) pairs[k++] = left[i++];
        while (j < right.size()) pairs[k++] = right[j++];
    }
}

int PmergeMe::binarySearchDeque(const std::deque<int>& arr, int value, int end) {
    int left = 0, right = end;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}

void PmergeMe::insertionSortDeque(std::deque<int>& mainChain, const std::deque<int>& pendingElements) {
    if (pendingElements.empty()) return;
    
    std::vector<size_t> jacobsthal = generateJacobsthalSequence(pendingElements.size());
    std::vector<bool> inserted(pendingElements.size(), false);
    
    // Insert elements using Jacobsthal sequence
    for (size_t i = 0; i < jacobsthal.size(); ++i) {
        size_t idx = jacobsthal[i] - 1;
        if (idx < pendingElements.size() && !inserted[idx]) {
            int pos = binarySearchDeque(mainChain, pendingElements[idx], mainChain.size());
            mainChain.insert(mainChain.begin() + pos, pendingElements[idx]);
            inserted[idx] = true;
        }
    }
    
    // Insert remaining elements
    for (size_t i = 0; i < pendingElements.size(); ++i) {
        if (!inserted[i]) {
            int pos = binarySearchDeque(mainChain, pendingElements[i], mainChain.size());
            mainChain.insert(mainChain.begin() + pos, pendingElements[i]);
        }
    }
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr) {
    if (arr.size() <= 1) return;
    
    bool hasOdd = (arr.size() % 2 == 1);
    int oddElement = hasOdd ? arr.back() : 0;
    
    if (hasOdd) arr.pop_back();
    
    // Create pairs and sort them
    std::deque<std::pair<int, int> > pairs = createPairsDeque(arr);
    sortPairsDeque(pairs);
    
    // Create main chain and pending elements
    std::deque<int> mainChain;
    std::deque<int> pendingElements;
    
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        pendingElements.push_back(pairs[i].second);
    }
    
    // Insert pending elements using Ford-Johnson algorithm
    insertionSortDeque(mainChain, pendingElements);
    
    // Insert odd element if exists
    if (hasOdd) {
        int pos = binarySearchDeque(mainChain, oddElement, mainChain.size());
        mainChain.insert(mainChain.begin() + pos, oddElement);
    }
    
    arr = mainChain;
}

void PmergeMe::printSequence(const std::vector<int>& arr, const std::string& prefix) {
    std::cout << prefix;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (i > 0) std::cout << " ";
        std::cout << arr[i];
        if (i >= 4 && arr.size() > 10) {
            std::cout << " [...]";
            break;
        }
    }
    std::cout << std::endl;
}

void PmergeMe::sortAndTime() {
    // Print before sorting
    printSequence(_vectorData, "Before: ");
    
    // Make copies for timing
    std::vector<int> vectorCopy = _vectorData;
    std::deque<int> dequeCopy = _dequeData;
    
    // Time vector sorting
    struct timeval start, end;
    gettimeofday(&start, NULL);
    mergeInsertSortVector(vectorCopy);
    gettimeofday(&end, NULL);
    double vectorTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
    
    // Time deque sorting
    gettimeofday(&start, NULL);
    mergeInsertSortDeque(dequeCopy);
    gettimeofday(&end, NULL);
    double dequeTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
    
    // Print after sorting
    printSequence(vectorCopy, "After:  ");
    
    // Print timing information
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Time to process a range of " << _vectorData.size() 
              << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _dequeData.size() 
              << " elements with std::deque  : " << dequeTime << " us" << std::endl;
}