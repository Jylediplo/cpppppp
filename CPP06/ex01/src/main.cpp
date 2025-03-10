#include "../headers/Serializer.hpp"


int main(void)
{
    Data data = {1, "fredo"};
    
    std::cout << &data << std::endl;
    uintptr_t raw =  Serializer::serialize(&data);
    Data * data1 = Serializer::deserialize(raw);
    std::cout << data1 << std::endl;
    std::cout << data1->id << std::endl;

    if (data1 == &data)
    {
        std::cout << "Serialization and deserialization worked correctly!" << std::endl;
    } else {
        std::cout << "Something went wrong with serialization/deserialization!" << std::endl;
    }
    return 0;
}
