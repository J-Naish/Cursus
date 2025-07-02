#include "../include/ShrubberyCreationForm.hpp"

// constructors
ShrubberyCreationForm::ShrubberyCreationForm() :
    AForm::AForm("Shrubbery Creation Form", 145, 137),
    target_("undefined") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
    AForm::AForm("Shrubbery Creation Form", 145, 137),
    target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
    AForm::AForm(other),
    target_(other.getTarget()) {}


// destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}


// operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    AForm::operator=(other);
    this->target_ = other.target_;
    return *this;
}


// getters
const std::string& ShrubberyCreationForm::getTarget() const {
    return this->target_;
}


void ShrubberyCreationForm::execute(const Bureaucrat& executer) const {

}
