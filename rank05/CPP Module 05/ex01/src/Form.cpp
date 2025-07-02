#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

// constructors
Form::Form() :
    name_("undefined"),
    is_signed_(false),
    grade_to_sign_(kHighestGrade),
    grade_to_execute_(kHighestGrade) {}

Form::Form(const std::string& name) :
    name_(name),
    is_signed_(false),
    grade_to_sign_(kHighestGrade),
    grade_to_execute_(kHighestGrade) {}

Form::Form(int grade_to_sign, int grade_to_execute) :
    name_("undefined"),
    is_signed_(false),
    grade_to_sign_(grade_to_sign),
    grade_to_execute_(grade_to_execute)
{
    if (grade_to_sign < kHighestGrade || grade_to_execute < kHighestGrade) {
        throw Form::GradeTooHighException();
    } else if (grade_to_sign_ > kLowestGrade || grade_to_execute_ > kLowestGrade) {
        throw Form::GradeTooLowException();
    }
}

Form::Form(const std::string& name, int grade_to_sign, int grade_to_execute) :
    name_(name),
    is_signed_(false),
    grade_to_sign_(grade_to_sign),
    grade_to_execute_(grade_to_execute)
{
    if (grade_to_sign < kHighestGrade || grade_to_execute < kHighestGrade) {
        throw Form::GradeTooHighException();
    } else if (grade_to_sign_ > kLowestGrade || grade_to_execute_ > kLowestGrade) {
        throw Form::GradeTooLowException();
    }
}

Form::Form(const Form& other) :
    name_(other.getName()),
    is_signed_(other.getIsSigned()),
    grade_to_sign_(other.getGradeToSign()),
    grade_to_execute_(other.getGradeToExecute()) {}


// destructor
Form::~Form() {}


// operators
Form& Form::operator=(const Form& other) {
    (void)other;
    return *this;
}


// getters
const std::string& Form::getName() const {
    return this->name_;
}

bool Form::getIsSigned() const {
    return this->is_signed_;
}

int Form::getGradeToSign() const {
    return this->grade_to_sign_;
}

int Form::getGradeToExecute() const {
    return this->grade_to_execute_;
}



// functions
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > this->grade_to_sign_) {
        throw Form::GradeTooLowException();
    } else if (!this->is_signed_) {
        this->is_signed_ = true;
    }
}



// exceptions
const char* Form::GradeTooHighException::what() const throw() {
    std::stringstream ss;
    ss << "Form grade is too high (must be between " << kHighestGrade << " and " << kLowestGrade << ")";
    static std::string msg = ss.str();
    return msg.c_str();
}

const char* Form::GradeTooLowException::what() const throw() {
    std::stringstream ss;
    ss << "Form grade is too low (must be between " << kHighestGrade << " and " << kLowestGrade << ")";
    static std::string msg = ss.str();
    return msg.c_str();
}



// << stream
std::ostream& operator<<(std::ostream& out, const Form& f) {
    out << f.getName() << " form"
        << ", `is signed`: " << f.getIsSigned()
        << ", `grade to sign`: " << f.getGradeToSign()
        << ", `grade to execute`: " << f.getGradeToExecute();
    return out;
}
