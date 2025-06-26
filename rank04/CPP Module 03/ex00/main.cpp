#include "ClapTrap.hpp"

int main() {

    ClapTrap jonathan = ClapTrap("Jonathan Joestar");

    ClapTrap jojo = jonathan;

    ClapTrap mobs[3];

    jojo.attack("Dio");
    jojo.setAttackDamage(2);

    jojo.attack("Dio");
    jojo.attack("Dio");
    jojo.attack("Dio");
    jojo.attack("Dio");

    jojo.takeDamage(7);
    jojo.beRepaired(2);

    jojo.attack("Dio");
    jojo.attack("Dio");
    jojo.attack("Dio");
    jojo.attack("Dio");
    jojo.attack("Dio");

    jojo.takeDamage(6);


    return 0;
}
