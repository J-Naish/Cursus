#pragma once
#ifndef SHRUBBERY_CREATION_FORM_H_
#define SHRUBBERY_CREATION_FORM_H_

#include "AForm.hpp"


class ShrubberyCreationForm : public AForm {

    public:

        // constructors
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);

        // destructor
        ~ShrubberyCreationForm();

        // operator
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

        // getters
        const std::string&   getTarget() const;

        // member functions
        void                 execute(const Bureaucrat& executer) const;

        // exceptions
        class FileOpenFailedException : public std::exception {
            public:
            const char* what() const throw();
        };


    private:

        std::string target_;

};


std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& form);


#endif
