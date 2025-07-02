#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"

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


// member functions
void ShrubberyCreationForm::execute(const Bureaucrat& executer) const {
    // validation
    if (!this->is_signed_) {
        throw AForm::FormNotSignedException();
    }
    if (executer.getGrade() > this->grade_to_execute_) {
        throw AForm::GradeTooLowException();
    }

    // create a file
    std::string file_name = this->target_ + "_shrubbery";
    std::ofstream output_file(file_name.c_str());

    if (!output_file.is_open()) {
        throw ShrubberyCreationForm::FileOpenFailedException();
    }

    // ascii tree
    output_file << "       _-_\n";
    output_file << "    /~~   ~~\\\n";
    output_file << " /~~         ~~\\\n";
    output_file << "{               }\n";
    output_file << " \\  _-     -_  /\n";
    output_file << "   ~  \\\\ //  ~\n";
    output_file << "_- -   | | _- _\n";
    output_file << "  _ -  | |   -_\n";
    output_file << "      // \\\\\n";
    output_file << "\n";
    output_file << "      ccee88oo\n";
    output_file << "  C8O8O8Q8PoOb o8oo\n";
    output_file << " dOB69QO8PdUOpugoO9bD\n";
    output_file << "CgggbU8OU qOp qOdoUOdcb\n";
    output_file << "    6OuU  /p u gcoUodpP\n";
    output_file << "      \\\\//  /douUP\n";
    output_file << "        \\\\////\n";
    output_file << "         |||/\\\n";
    output_file << "         |||\\/\n";
    output_file << "         |||||\n";
    output_file << "   .....//||||\\.....\n";

    output_file.close();
}


const char* ShrubberyCreationForm::FileOpenFailedException::what() const throw() {
    return "Failed to open or create a file";
}


std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& form) {
    out << "ShrubberyCreationForm [" << form.getName() << "] (Target: " << form.getTarget() 
        << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
        << ", Sign Grade: " << form.getGradeToSign()
        << ", Execute Grade: " << form.getGradeToExecute() << ")";
    return out;
}
