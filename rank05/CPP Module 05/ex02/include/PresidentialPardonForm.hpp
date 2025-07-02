#pragma once
#ifndef PRESIDENTIAL_PARDON_FORM_H_
#define PRESIDENTIAL_PARDON_FORM_H_

#include "AForm.hpp"


class PresidentialPardonForm : public AForm {

    public:

        // constructors
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);

        // destructor
        ~PresidentialPardonForm();

        // operator
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

        // getters
        const std::string&   getTarget() const;

        // member functions
        void                 execute(const Bureaucrat& executer) const;


        private:

            std::string target_;

};


#endif
