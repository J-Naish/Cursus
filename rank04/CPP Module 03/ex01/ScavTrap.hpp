#pragma once
#ifndef SCAV_TRAP_H
#define SCAV_TRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

    public:

        static const unsigned int kDefaultHitPoints = 100;
        static const unsigned int kDefaultEnergyPoints = 50;
        static const unsigned int kDefaultAttackDamage = 20;

        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& other);
        ~ScavTrap();
        ScavTrap& operator=(const ScavTrap& other);

        void attack(const std::string& target);

        void guardGate();

};


#endif
