#pragma once
#ifndef CURE_H
#define CURE_H

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure
{
    private:

        std::string type_;

    public:

        Cure();
        Cure(const Cure& other);
        ~Cure();
        Cure& operator=(const Cure& other);

        Cure* clone();
        void use(ICharacter& target);

};



#endif