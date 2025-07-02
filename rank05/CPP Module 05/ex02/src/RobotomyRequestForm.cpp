#include "../include/RobotomyRequestForm.hpp"
#include "../include/Bureaucrat.hpp"

// constructors
RobotomyRequestForm::RobotomyRequestForm() :
    AForm::AForm("Robotomy Request Form", 72, 45),
    target_("undefined") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
    AForm::AForm("Robotomy Request Form", 72, 45),
    target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
    AForm::AForm(other),
    target_(other.getTarget()) {}


// destructor
RobotomyRequestForm::~RobotomyRequestForm() {}


// operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    AForm::operator=(other);
    this->target_ = other.target_;
    return *this;
}


// getters
const std::string& RobotomyRequestForm::getTarget() const {
    return this->target_;
}


// member functions
void RobotomyRequestForm::execute(const Bureaucrat& executer) const {
    // validation
    if (!this->is_signed_) {
        throw AForm::FormNotSignedException();
    }
    if (executer.getGrade() > this->grade_to_execute_) {
        throw AForm::GradeTooLowException();
    }

    // set seed of random number by current time
    std::srand(std::time(NULL));

    // get boolean (50% true, 50% false) by generating random number
    bool random = std::rand() % 2;

    if (random) {
        std::cout << this->target_ << " has been successfully robotomized." << std::endl;
    } else {
        std::cout << "Failed to robotomize " << this->target_ << "." << std::endl;
    }

}
