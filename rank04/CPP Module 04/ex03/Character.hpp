#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"

class Character : public ICharacter {

    private:

        std::string name_;
        static const unsigned char kNumSlot = 4;
        AMateria* inventory[kNumSlot];
        unsigned char num_occupied_slots_;

    public:
        Character();
        Character(std::string name);
        Character(const Character& other);
        ~Character();
        Character& operator=(const Character& other);

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

};

#endif