#pragma once
#ifndef WRONG_CAT_H
#define WRONG_CAT_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

    public:

        WrongCat();
        WrongCat(std::string type);
        WrongCat(const WrongCat& other);
        ~WrongCat();
        WrongCat& operator=(const WrongCat& other);

        void makeSound() const;

};



#endif