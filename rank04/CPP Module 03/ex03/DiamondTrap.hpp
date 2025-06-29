#pragma once
#ifndef DIAMOND_TRAP_H
#define DIAMOND_TRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

    private:

        std::string name_;

    public:

        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& other);
        ~DiamondTrap();
        DiamondTrap& operator=(const DiamondTrap& other);

        void attack(const std::string& target);
        void whoAmI();

};




#endif
