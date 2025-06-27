#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

    public:

        ScavTrap();
        ScavTrap(std::string name);

        void guardGate();

};