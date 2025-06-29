#pragma once
#ifndef FRAG_TRAP_H
#define FRAG_TRAP_H
#include "ClapTrap.hpp"

#include <iostream>

class FragTrap : virtual public ClapTrap {

    public:

        FragTrap();
        FragTrap(std::string name);
        ~FragTrap();

        void highFivesGuys(void);

};

#endif
