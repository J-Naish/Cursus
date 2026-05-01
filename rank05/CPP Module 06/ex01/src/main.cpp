#include "Serializer.hpp"
#include "Data.hpp"

#include <iostream>

int main() {

    Data original;
    original.name = "test";
    original.value = 42;

    uintptr_t raw = Serializer::serialize(&original);
    Data* restored = Serializer::deserialize(raw);

    std::cout << "original  ptr: " << &original << std::endl;
    std::cout << "raw       val: " << raw << std::endl;
    std::cout << "restored  ptr: " << restored << std::endl;

    if (restored == &original) {
        std::cout << "[PASS] restored pointer equals original" << std::endl;
    } else {
        std::cout << "[FAIL] restored pointer differs from original" << std::endl;
        return 1;
    }

    std::cout << "restored->name:  " << restored->name << std::endl;
    std::cout << "restored->value: " << restored->value << std::endl;

    return 0;
}
