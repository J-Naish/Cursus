#pragma once
#ifndef SCAV_TRAP_H
#define SCAV_TRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

    public:

        ScavTrap();
        ScavTrap(std::string name);

        void guardGate();

};

#endif
