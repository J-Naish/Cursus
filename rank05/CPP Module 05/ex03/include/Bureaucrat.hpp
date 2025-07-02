#pragma once
#ifndef BUREAUCRAT_H_
#define BUREAUCRAT_H_

#include <string>
#include <exception>
#include <iostream>
#include <sstream>
#include "constants.hpp"
#include "AForm.hpp"


class Bureaucrat {

    public:

        // constructors
        Bureaucrat();
        Bureaucrat(const std::string& name);
        Bureaucrat(int grade);
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);

        // destructor
        ~Bureaucrat();

        // operator
        Bureaucrat& operator=(const Bureaucrat& other);


        // getters
        const std::string&  getName() const;
        int                 getGrade() const;


        // functions
        void                incrementGrade();
        void                decrementGrade();
        void                signForm(AForm& form) const;
        void                executeForm(const AForm& form) const;


        // exceptions
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };


    private:

        const std::string   name_;
        int                 grade_;

};


std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);


#endif
