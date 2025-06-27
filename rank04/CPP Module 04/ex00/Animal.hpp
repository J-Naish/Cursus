#pragma once
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal {

    protected:

        std::string type;

    public:

        Animal();
        Animal(std::string type);
        Animal(const Animal& other);
        ~Animal();
        Animal& operator=(const Animal& other);

        void makeSound();

};

#endif