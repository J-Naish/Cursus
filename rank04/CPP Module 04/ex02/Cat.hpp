#pragma once
#ifndef CAT_H
#define CAT_H

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {

    private:
        Brain* brain;

    public:

        Cat();
        Cat(std::string type);
        Cat(const Cat& other);
        virtual ~Cat();
        Cat& operator=(const Cat& other);

        void makeSound() const;

};



#endif