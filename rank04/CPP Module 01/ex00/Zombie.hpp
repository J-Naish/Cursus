#pragma once
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie {


    public:

        void announce( void );

        Zombie( std::string name );
        ~Zombie( void );

    private:

        std::string name;

};

#endif