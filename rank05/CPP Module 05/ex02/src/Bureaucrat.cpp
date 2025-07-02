#include "../include/Bureaucrat.hpp"


Bureaucrat::Bureaucrat() :
    name_("undefined"),
    grade_(kLowestGrade) {}


Bureaucrat::Bureaucrat(const std::string& name) :
    name_(name),
    grade_(kLowestGrade) {}


Bureaucrat::Bureaucrat(int grade) :
    name_("undefined")
{
    if (grade > kLowestGrade) {
        throw Bureaucrat::GradeTooLowException();
    } else if (grade < kHighestGrade) {
        throw Bureaucrat::GradeTooHighException();
    } else {
        this->grade_ = grade;
    }
}


Bureaucrat::Bureaucrat(const std::string& name, int grade) :
    name_(name)
{
    if (grade > kLowestGrade) {
        throw Bureaucrat::GradeTooLowException();
    } else if (grade < kHighestGrade) {
        throw Bureaucrat::GradeTooHighException();
    } else {
        this->grade_ = grade;
    }
}


Bureaucrat::Bureaucrat(const Bureaucrat& other) :
    name_(other.getName()),
    grade_(other.getGrade()) {}


Bureaucrat::~Bureaucrat() {}


Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->grade_ = other.getGrade();
    }
    return *this;
}

const std::string& Bureaucrat::getName() const {
    return this->name_;
}

int Bureaucrat::getGrade() const {
    return this->grade_;
}


void Bureaucrat::incrementGrade() {
    if (this->grade_ - 1 < kHighestGrade) {
        throw Bureaucrat::GradeTooHighException();
    } else {
        this->grade_ -= 1;
    }
}


void Bureaucrat::decrementGrade() {
    if (this->grade_ + 1 > kLowestGrade) {
        throw Bureaucrat::GradeTooLowException();
    } else {
        this->grade_ += 1;
    }
}


void Bureaucrat::signForm(AForm& form) const {
    if (form.getIsSigned()) {
        std::cout << form.getName() << " has already been signed." << std::endl;
        return;
    }
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    } catch (std::exception& _) {
        std::cout << this->getName() << " couldn't sign " << form.getName() << " because the grade is not high enough." << std::endl;
    }
}


const char* Bureaucrat::GradeTooHighException::what() const throw() {
    std::stringstream ss;
    ss << kHighestGrade;
    std::string highest_grade_str = ss.str();

    static std::string msg = "Grade too high; the grade cannot be less than " + highest_grade_str;
    return msg.c_str();
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    std::stringstream ss;
    ss << kLowestGrade;
    std::string lowest_grade_str = ss.str();

    static std::string msg = "Grade too low; the grade cannot be more than " + lowest_grade_str;
    return msg.c_str();
}


std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}
