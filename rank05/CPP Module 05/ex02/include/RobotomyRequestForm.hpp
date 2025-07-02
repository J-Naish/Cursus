#pragma once
#ifndef ROBOTOMY_REQUEST_FORM_H_
#define ROBOTOMY_REQUEST_FORM_H_

#include "AForm.hpp"


class RobotomyRequestForm : public AForm{

    public:

        // constructors
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);

        // destructor
        ~RobotomyRequestForm();

        // operator
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

        // getters
        const std::string&   getTarget() const;

        // member functions
        void                 execute(const Bureaucrat& executer) const;


    private:

        std::string target_;

};


#endif
