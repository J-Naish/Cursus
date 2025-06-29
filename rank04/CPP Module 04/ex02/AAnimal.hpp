#pragma once
#ifndef AAAnimal__H
#define AANIMAL__H

#include <iostream>
#include <string>

class AAnimal {

    protected:

        std::string type;

    public:

        AAnimal();
        AAnimal(std::string type);
        AAnimal(const AAnimal& other);
        virtual ~AAnimal();
        AAnimal& operator=(const AAnimal& other);

        std::string getType() const;
        void setType(std::string type);

        virtual void makeSound() const = 0;

};

#endif
