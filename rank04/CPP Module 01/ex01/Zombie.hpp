#pragma once
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie {


    public:

        void announce( void );

        Zombie( std::string name );
        Zombie( void );
        ~Zombie( void );

        void set_name(std::string name);

    private:

        std::string name;

};

#endif