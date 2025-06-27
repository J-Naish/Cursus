#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    const int numAnimas = 4;
    Animal* animals[numAnimas];

    std::cout << "=== Testing Memory Leak ===" << std::endl;
    for (int i = 0; i < numAnimas; i++) {
        if (i % 2 == 0) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }
    animals[0]->makeSound();
    animals[1]->makeSound();
    for (int i = 0; i < numAnimas; i++) {
        delete animals[i];
    }



    std::cout << "=== Testing Deep Copy ===" << std::endl;

    Dog dog1;
    Dog dog2;

    std::cout << "Before assignment:" << std::endl;
    std::cout << "Dog1 address: " << &dog1 << std::endl;
    std::cout << "Dog2 address: " << &dog2 << std::endl;

    dog2 = dog1;

    std::cout << "\nAfter assignment (addresses should be different):" << std::endl;
    std::cout << "Dog1 address: " << &dog1 << std::endl;
    std::cout << "Dog2 address: " << &dog2 << std::endl;

    return 0;
}
