#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );


void test(int n, std::string name) {

    std::cout << "creating " << n << " zombies named " << name << std::endl;

    Zombie* horde = zombieHorde(n, name);

    for (int i = 0; i < n; i++) {
        horde[i].announce();
    }

    delete[] horde;

    std::cout << std::endl;
}


int main ( void ) {

    int nums[] = { 1, 2, 3, 4, 5, 6 };

    std::string names[] = {
        "Alice",
        "Bob",
        "Charlie",
        "David",
        "Elena",
        "Freddie"
    };

    size_t size = sizeof(nums) / sizeof(int);

    for (size_t i = 0; i < size; i++) {
        test(nums[i], names[i]);
    }

}
