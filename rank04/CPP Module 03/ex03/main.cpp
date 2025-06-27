#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {

    ClapTrap jonathan = ClapTrap("Jonathan Joestar");

    jonathan.attack("Dio");

    DiamondTrap george = DiamondTrap("George");
    george.whoAmI();
    george.attack("cars");

    return 0;
}
