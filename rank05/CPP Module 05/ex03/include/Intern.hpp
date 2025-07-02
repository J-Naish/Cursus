#pragma once
#ifndef INTERN_H_
#define INTERN_H_

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {

    public:

        // constructors
        Intern();
        Intern(const Intern& other);

        // destructor
        ~Intern();

        // operator
        Intern& operator=(const Intern& other);

        // member functions
        AForm* makeForm(const std::string& form_name, const std::string form_target) const;

};

#endif
