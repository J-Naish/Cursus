#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

    ClapTrap jonathan = ClapTrap("Jonathan Joestar");

    ClapTrap jojo = jonathan;

    ClapTrap mobs[3];

    jojo.attack("Dio");
    jojo.setAttackDamage(2);

    ScavTrap zepeli = ScavTrap("Zepeli");
    zepeli.guardGate();
    zepeli.attack("Dio");


    FragTrap speedwagon = FragTrap("Speedwagon");

    speedwagon.highFivesGuys();


    return 0;
}
