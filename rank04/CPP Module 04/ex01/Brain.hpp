#pragma once
#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include <string>

class Brain {

    private:

        std::string ideas[100];

    public:

        Brain();
        Brain(const Brain& other);
        ~Brain();
        Brain& operator=(const Brain& other);

};

#endif