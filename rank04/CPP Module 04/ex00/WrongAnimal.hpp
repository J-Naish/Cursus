#pragma once
#ifndef WRONG_ANIMAL_H
#define WRONG_ANIMAL_H

#include <iostream>
#include <string>

class WrongAnimal {

    protected:

        std::string type;

    public:

        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal& other);
        ~WrongAnimal();
        WrongAnimal& operator=(const WrongAnimal& other);

        std::string getType() const;
        void setType(std::string type);

        // virtual void makeSound() const;
        void makeSound() const;

};

#endif
