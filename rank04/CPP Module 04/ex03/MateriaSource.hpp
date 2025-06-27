#pragma once
#ifndef MATERIA_SOURCE_H
#define MATERIA_SOURCE_H

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

    private:
        static const unsigned short kNumSlot = 4;
        AMateria* source_[kNumSlot];
        unsigned short num_memorized;

    public:
        MateriaSource();
        MateriaSource(const MateriaSource& other);
        ~MateriaSource();
        MateriaSource& operator=(const MateriaSource& other);

        void learnMateria(AMateria* m);
        AMateria* createMateria(std::string const & type);

};

#endif