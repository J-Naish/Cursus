#pragma once
#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include <string>

class Brain {

    public:

        Brain();
        Brain(const Brain& other);
        ~Brain();
        Brain& operator=(const Brain& other);

        static const int kSize = 100;

    private:

        std::string ideas[kSize];


};

#endif