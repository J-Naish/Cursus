#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
    // AAnimal a = new AAnimal();

    Dog d1;
    Cat c1;

    d1.makeSound();
    c1.makeSound();

    Dog* d2 = new Dog();
    Cat* c2 = new Cat();

    d2->makeSound();
    c2->makeSound();

    delete d2;
    delete c2;

}
