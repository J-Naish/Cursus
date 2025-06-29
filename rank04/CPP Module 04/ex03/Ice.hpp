#pragma once
#ifndef ICE_H
#define ICE_H

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {

    public:

        Ice();
        Ice(const Ice& other);
        ~Ice();
        Ice& operator=(const Ice& other);

        Ice* clone() const;
        void use(ICharacter& target);

};




#endif
