#pragma once
#ifndef CLAP_TRAP_H
#define CLAP_TRAP_H

#include <string>

class ClapTrap
{
    private:

        std::string name_;
        unsigned int hit_points_;
        unsigned int energy_points_;
        unsigned int attack_damage_;


    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);
        ~ClapTrap();
        ClapTrap& operator=(const ClapTrap& other);


        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);


};



#endif