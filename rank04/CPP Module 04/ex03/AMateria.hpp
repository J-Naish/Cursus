#pragma once
#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
    protected:
        std::string type_;

    public:

        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria& other);
        virtual ~AMateria();
        virtual AMateria& operator=(const AMateria& other);

        std::string const & getType() const;

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif