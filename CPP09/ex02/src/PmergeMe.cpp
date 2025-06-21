#include "../headers/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other) : _vectorData(other._vectorData), _dequeData(other._dequeData)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::addNumber(int num)
{
    _vectorData.push_back(num);
    _dequeData.push_back(num);
}

double PmergeMe::getTime() const
{
    return static_cast<double>(clock()) / CLOCKS_PER_SEC * 1000000; // microseconds
}

void PmergeMe::printSequence(const std::vector<int>& arr, const std::string& prefix) const
{
    std::cout << prefix;
    for (size_t i = 0; i < arr.size() && i < 5; ++i)
    {
        std::cout << arr[i];
        if (i < arr.size() - 1 && i < 4)
            std::cout << " ";
    }
    if (arr.size() > 5)
        std::cout << " [...]";
    std::cout << std::endl;
}

void PmergeMe::insertionSortVector(std::vector<int>& arr, int left, int right)
{
    for (int i = left + 1; i <= right; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::mergeVector(std::vector<int>& arr, int left, int mid, int right)
{
    std::vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);
    
    size_t i = 0, j = 0;
    int k = left;
    
    while (i < leftArr.size() && j < rightArr.size())
    {
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }
    
    while (i < leftArr.size())
        arr[k++] = leftArr[i++];
    
    while (j < rightArr.size())
        arr[k++] = rightArr[j++];
}

void PmergeMe::fordJohnsonVector(std::vector<int>& arr)
{
    int n = arr.size();
    if (n <= 1)
        return;
    
    // Use insertion sort for small arrays (Ford-Johnson optimization)
    if (n <= 10)
    {
        insertionSortVector(arr, 0, n - 1);
        return;
    }
    
    // Divide
    int mid = n / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());
    
    // Conquer
    fordJohnsonVector(left);
    fordJohnsonVector(right);
    
    // Merge back into original array
    std::copy(left.begin(), left.end(), arr.begin());
    std::copy(right.begin(), right.end(), arr.begin() + mid);
    
    mergeVector(arr, 0, mid - 1, n - 1);
}

void PmergeMe::insertionSortDeque(std::deque<int>& arr, int left, int right)
{
    for (int i = left + 1; i <= right; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::mergeDeque(std::deque<int>& arr, int left, int mid, int right)
{
    std::deque<int> leftArr;
    std::deque<int> rightArr;
    
    for (int i = left; i <= mid; ++i)
        leftArr.push_back(arr[i]);
    
    for (int i = mid + 1; i <= right; ++i)
        rightArr.push_back(arr[i]);
    
    size_t i = 0, j = 0;
    int k = left;
    
    while (i < leftArr.size() && j < rightArr.size())
    {
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }
    
    while (i < leftArr.size())
        arr[k++] = leftArr[i++];
    
    while (j < rightArr.size())
        arr[k++] = rightArr[j++];
}

void PmergeMe::fordJohnsonDeque(std::deque<int>& arr)
{
    int n = arr.size();
    if (n <= 1)
        return;
    
    // Use insertion sort for small arrays (Ford-Johnson optimization)
    if (n <= 10)
    {
        insertionSortDeque(arr, 0, n - 1);
        return;
    }
    
    // Divide
    int mid = n / 2;
    std::deque<int> left;
    std::deque<int> right;
    
    for (int i = 0; i < mid; ++i)
        left.push_back(arr[i]);
    
    for (int i = mid; i < n; ++i)
        right.push_back(arr[i]);
    
    // Conquer
    fordJohnsonDeque(left);
    fordJohnsonDeque(right);
    
    // Merge back into original array
    for (int i = 0; i < mid; ++i)
        arr[i] = left[i];
    
    for (size_t i = 0; i < right.size(); ++i)
        arr[mid + i] = right[i];
    
    mergeDeque(arr, 0, mid - 1, n - 1);
}

void PmergeMe::sort()
{
    if (_vectorData.empty())
        return;
    
    // Print unsorted sequence
    printSequence(_vectorData, "Before: ");
    
    // Sort with vector and measure time
    std::vector<int> vectorCopy = _vectorData;
    double startTime = getTime();
    fordJohnsonVector(vectorCopy);
    double vectorTime = getTime() - startTime;
    
    // Sort with deque and measure time
    std::deque<int> dequeCopy = _dequeData;
    startTime = getTime();
    fordJohnsonDeque(dequeCopy);
    double dequeTime = getTime() - startTime;
    
    // Print sorted sequence (using vector result)
    printSequence(vectorCopy, "After:  ");
    
    // Print timing information
    std::cout << "Time to process a range of " << _vectorData.size() 
              << " elements with std::vector : " << vectorTime << " us" << std::endl;
    
    std::cout << "Time to process a range of " << _dequeData.size() 
              << " elements with std::deque : " << dequeTime << " us" << std::endl;
}