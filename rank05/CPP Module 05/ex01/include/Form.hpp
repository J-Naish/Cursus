#pragma once
#ifndef FORM_H_
#define FORM_H_

#include <string>
#include <exception>
#include <iostream>
#include <sstream>
#include "constants.hpp"
#include "Bureaucrat.hpp"


class Form {


    public:

        // constructors
        Form();
        Form(std::string& name);
        Form(int grade_to_sign, int grade_to_execute);
        Form(std::string& name, int grade_to_sign, int grade_to_execute);
        Form(const Form& other);

        // destructor
        ~Form();

        // operator
        Form& operator=(const Form& other);


        // getters
        const std::string& getName() const;
        bool               getIsSigned() const;
        int                getGradeToSign() const;
        int                getGradeToExecute() const;


        // functions
        void               beSigned(const Bureaucrat& bureaucrat);



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

        const std::string  name_;
        bool               is_signed_;
        const int          grade_to_sign_;
        const int          grade_to_execute_;


};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif
