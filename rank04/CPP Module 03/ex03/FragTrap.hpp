#pragma once
#ifndef FRAG_TRAP_H
#define FRAG_TRAP_H
#include "ClapTrap.hpp"

#include <iostream>

class FragTrap : public ClapTrap {

    public:

      static const unsigned int kDefaultHitPoints = 100;
      static const unsigned int kDefaultEnergyPoints = 100;
      static const unsigned int kDefaultAttackDamage = 30;

      FragTrap();
      FragTrap(std::string name);
      FragTrap(const FragTrap& other);
      ~FragTrap();
      FragTrap& operator=(const FragTrap& other);

      void highFivesGuys(void);

};

#endif
