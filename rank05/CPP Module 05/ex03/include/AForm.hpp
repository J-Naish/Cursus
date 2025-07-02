#pragma once
#ifndef A_FORM_H_
#define A_FORM_H_

#include <string>
#include <exception>
#include <iostream>
#include <sstream>
#include <fstream>
#include "constants.hpp"

class Bureaucrat;

class AForm {


    public:

        // constructors
        AForm();
        AForm(const std::string& name);
        AForm(int grade_to_sign, int grade_to_execute);
        AForm(const std::string& name, int grade_to_sign, int grade_to_execute);
        AForm(const AForm& other);

        // destructor
        ~AForm();

        // operator
        AForm& operator=(const AForm& other);


        // getters
        const std::string& getName() const;
        bool               getIsSigned() const;
        int                getGradeToSign() const;
        int                getGradeToExecute() const;


        // functions
        void               beSigned(const Bureaucrat& signer);
        virtual void       execute(const Bureaucrat& executer) const = 0;


        // exceptions
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        class FormNotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };


    protected:

        const std::string  name_;
        bool               is_signed_;
        const int          grade_to_sign_;
        const int          grade_to_execute_;


};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif
