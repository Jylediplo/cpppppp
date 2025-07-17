 #include "../headers/iter.hpp"

template <typename T>
void printElement(const T &element)
{
    std::cout << element << std::endl;
}

template <typename T>
void increment(T &element)
{
    ++element;
}

int main()
{
    int intArray[5] = {1, 2, 3, 4, 5};

    std::cout << "Int array before increment:" << std::endl;
    iter(intArray, 5, printElement<int>);

    iter(intArray, 5, increment<int>);

    std::cout << "Int array after increment:" << std::endl;
    iter(intArray, 5, printElement<int>);

    float floatArray[3] = {1.1f, 2.2f, 3.3f};
    iter(floatArray, 3, printElement<float>);
    iter(floatArray, 3, increment<float>);
    iter(floatArray, 3, printElement<float>);


    std::string strArray[3] = {"hello", "world", "!"};

    std::cout << "String array:" << std::endl;
    iter(strArray, 3, printElement<std::string>);

    return 0;
}
