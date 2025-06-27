#pragma once
#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

    private:
        Brain* brain;

    public:

        Dog();
        Dog(std::string type);
        Dog(const Dog& other);
        virtual ~Dog();
        Dog& operator=(const Dog& other);

        void makeSound() const;

};



#endif