#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main( void ) {

    randomChump("Zombie A");

    Zombie* zombieB = newZombie("Zombie B");
    zombieB->announce();
    delete zombieB;

    return 0;
}