#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

// constructors
AForm::AForm() :
    name_("undefined"),
    is_signed_(false),
    grade_to_sign_(kHighestGrade),
    grade_to_execute_(kHighestGrade) {}

AForm::AForm(const std::string& name) :
    name_(name),
    is_signed_(false),
    grade_to_sign_(kHighestGrade),
    grade_to_execute_(kHighestGrade) {}

AForm::AForm(int grade_to_sign, int grade_to_execute) :
    name_("undefined"),
    is_signed_(false),
    grade_to_sign_(grade_to_sign),
    grade_to_execute_(grade_to_execute)
{
    if (grade_to_sign < kHighestGrade || grade_to_execute < kHighestGrade) {
        throw AForm::GradeTooHighException();
    } else if (grade_to_sign_ > kLowestGrade || grade_to_execute_ > kLowestGrade) {
        throw AForm::GradeTooLowException();
    }
}

AForm::AForm(const std::string& name, int grade_to_sign, int grade_to_execute) :
    name_(name),
    is_signed_(false),
    grade_to_sign_(grade_to_sign),
    grade_to_execute_(grade_to_execute)
{
    if (grade_to_sign < kHighestGrade || grade_to_execute < kHighestGrade) {
        throw AForm::GradeTooHighException();
    } else if (grade_to_sign_ > kLowestGrade || grade_to_execute_ > kLowestGrade) {
        throw AForm::GradeTooLowException();
    }
}

AForm::AForm(const AForm& other) :
    name_(other.getName()),
    is_signed_(other.getIsSigned()),
    grade_to_sign_(other.getGradeToSign()),
    grade_to_execute_(other.getGradeToExecute()) {}


// destructor
AForm::~AForm() {}


// operators
AForm& AForm::operator=(const AForm& other) {
    (void)other;
    return *this;
}


// getters
const std::string& AForm::getName() const {
    return this->name_;
}

bool AForm::getIsSigned() const {
    return this->is_signed_;
}

int AForm::getGradeToSign() const {
    return this->grade_to_sign_;
}

int AForm::getGradeToExecute() const {
    return this->grade_to_execute_;
}



// functions
void AForm::beSigned(const Bureaucrat& signer) {
    if (signer.getGrade() > this->grade_to_sign_) {
        throw AForm::GradeTooLowException();
    } else if (!this->is_signed_) {
        this->is_signed_ = true;
    }
}



// exceptions
const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "The form is not signed yet";
}

// << stream
std::ostream& operator<<(std::ostream& out, const AForm& f) {
    out << f.getName() << " form"
        << ", `is signed`: " << f.getIsSigned()
        << ", `grade to sign`: " << f.getGradeToSign()
        << ", `grade to execute`: " << f.getGradeToExecute();
    return out;
}
