#pragma once
#ifndef CLAP_TRAP_H
#define CLAP_TRAP_H

# ifndef GREEN
#  define GREEN "\033[32m"
# endif

# ifndef RED
#  define RED "\033[31m"
# endif

# ifndef YELLOW
#  define YELLOW "\033[33m"
# endif

# ifndef RESET
#  define RESET "\033[0m"
# endif

#include <string>

class ClapTrap
{
    private:

        std::string name_;
        unsigned int hit_points_;
        unsigned int energy_points_;
        unsigned int attack_damage_;

        static const unsigned int kEnergyCost = 1;


    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);
        ~ClapTrap();
        ClapTrap& operator=(const ClapTrap& other);


        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName() const;
        unsigned int getHitPoints() const;
        unsigned int getEnergyPoints() const;
        unsigned int getAttackDamage_() const;

        void setName(const std::string& name);
        void setHitPoints(const unsigned int& hit_points);
        void setEnergyPoints(const unsigned int& energy_points);
        void setAttackDamage(const unsigned int& attack_damage);

        bool isDead() const;
        bool isOutOfEnergy() const;

};



#endif