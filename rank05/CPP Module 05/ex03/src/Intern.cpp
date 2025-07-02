#include "../include/Intern.hpp"

// constructors
Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}


// destructor
Intern::~Intern() {}


// operator
Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}


// factory functions
static AForm* makeShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* makeRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* makePresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

// member functions
AForm* Intern::makeForm(const std::string& form_name, const std::string form_target) const {

    std::string form_list[] = {
        "ShrubberyCreationForm",
        "RobotomyRequestForm",
        "PresidentialPardonForm",
    };

    AForm* (*funcs[])(const std::string& target) = {
        &makeShrubberyCreationForm,
        &makeRobotomyRequestForm,
        &makePresidentialPardonForm,
    };

    for (int i = 0; i < 3; i++) {
        if (form_list[i] == form_name) {
            std::cout << "Intern creates " << form_name << " that targets " << form_target << "." << std::endl;
            return (funcs[i](form_target));
        }
    }

    std::cout << "Intern couldn't create " << form_name << " because it is not found." << std::endl;
    return NULL;

}
