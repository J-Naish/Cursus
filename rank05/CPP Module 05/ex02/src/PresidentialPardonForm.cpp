#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"

// constructors
PresidentialPardonForm::PresidentialPardonForm() :
    AForm::AForm("Presidential Pardon Form", 25, 5),
    target_("undefined") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
    AForm::AForm("Presidential Pardon Form", 25, 5),
    target_(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
    AForm::AForm(other),
    target_(other.getTarget()) {}


// destructor
PresidentialPardonForm::~PresidentialPardonForm() {}


// operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    AForm::operator=(other);
    this->target_ = other.target_;
    return *this;
}


// getters
const std::string& PresidentialPardonForm::getTarget() const {
    return this->target_;
}


// member functions
void PresidentialPardonForm::execute(const Bureaucrat& executer) const {
    // validation
    if (!this->is_signed_) {
        throw AForm::FormNotSignedException();
    }
    if (executer.getGrade() > this->grade_to_execute_) {
        throw AForm::GradeTooLowException();
    }

    std::cout << this->target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}


std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& form) {
    out << "PresidentialPardonForm [" << form.getName() << "] (Target: " << form.getTarget() 
        << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
        << ", Sign Grade: " << form.getGradeToSign()
        << ", Execute Grade: " << form.getGradeToExecute() << ")";
    return out;
}
