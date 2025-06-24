#pragma once
#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {

    public:

        Weapon(std::string type);
        ~Weapon();

        const std::string& getType() const;
        void setType(std::string type);


    private:

        std::string type;

};

#endif