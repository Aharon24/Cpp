#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;

    data.id = 42;
    data.name = "Aharon";
    data.value = 99.99;

    Data *original = &data;

    uintptr_t raw = Serializer::serialize(original);

    Data *restored = Serializer::deserialize(raw);

    std::cout << "Original pointer:  " << original << std::endl;
    std::cout << "Serialized value:  " << raw << std::endl;
    std::cout << "Restored pointer:  " << restored << std::endl;

    if (original == restored)
        std::cout << "\nSUCCESS: pointers are equal!" << std::endl;
    else
        std::cout << "\nERROR: pointers are different!" << std::endl;

    std::cout << "\nData content:" << std::endl;
    std::cout << "id:    " << restored->id << std::endl;
    std::cout << "name:  " << restored->name << std::endl;
    std::cout << "value: " << restored->value << std::endl;

    return 0;
}