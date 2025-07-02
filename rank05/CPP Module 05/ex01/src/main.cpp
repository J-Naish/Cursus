#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"
#include <iostream>

int main() {

    std::cout << "\n1. Testing Form basic constructors:" << std::endl;
    try {
        Form f1;
        std::cout << "Default constructor: " << f1 << std::endl;

        Form f2("Tax Form");
        std::cout << "Name constructor: " << f2 << std::endl;

        Form f3(50, 25);
        std::cout << "Grade constructor: " << f3 << std::endl;

        Form f4("Application Form", 75, 40);
        std::cout << "Name and grades constructor: " << f4 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n2. Testing Form grade validation in constructors:" << std::endl;
    try {
        Form highForm("Valid High Form", 1, 1);
        std::cout << "Valid highest grades: " << highForm << std::endl;

        Form lowForm("Valid Low Form", 150, 150);
        std::cout << "Valid lowest grades: " << lowForm << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n3. Testing invalid grades in Form constructors:" << std::endl;
    try {
        Form tooHigh("Invalid Form", 0, 50);
    } catch (const std::exception& e) {
        std::cout << "Grade to sign 0 exception: " << e.what() << std::endl;
    }

    try {
        Form tooLow("Invalid Form", 50, 151);
    } catch (const std::exception& e) {
        std::cout << "Grade to execute 151 exception: " << e.what() << std::endl;
    }

    std::cout << "\n4. Testing Form copy constructor and assignment:" << std::endl;
    try {
        Form original("Original Form", 50, 30);
        std::cout << "Original: " << original << std::endl;

        Form copy(original);
        std::cout << "Copy constructor: " << copy << std::endl;

        Form assigned("Assigned Form", 100, 80);
        assigned = original;
        std::cout << "Assignment operator: " << assigned << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n5. Testing Form getters:" << std::endl;
    try {
        Form f("Test Form", 42, 25);
        std::cout << "Name: " << f.getName() << std::endl;
        std::cout << "Is signed: " << (f.getIsSigned() ? "true" : "false") << std::endl;
        std::cout << "Grade to sign: " << f.getGradeToSign() << std::endl;
        std::cout << "Grade to execute: " << f.getGradeToExecute() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n6. Testing Form signing - successful case:" << std::endl;
    try {
        Form form("Signable Form", 50, 25);
        Bureaucrat bureaucrat("Alice", 30);

        std::cout << "Before signing: " << form << std::endl;
        std::cout << "Bureaucrat: " << bureaucrat << std::endl;

        form.beSigned(bureaucrat);
        std::cout << "After signing: " << form << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n7. Testing Form signing - bureaucrat grade too low:" << std::endl;
    try {
        Form form("High Security Form", 10, 5);
        Bureaucrat bureaucrat("Bob", 50);

        std::cout << "Form requiring grade 10: " << form << std::endl;
        std::cout << "Bureaucrat with grade 50: " << bureaucrat << std::endl;

        form.beSigned(bureaucrat);
        std::cout << "This should not print" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception when signing: " << e.what() << std::endl;
    }

    std::cout << "\n8. Testing Form signing - exactly at required grade:" << std::endl;
    try {
        Form form("Exact Grade Form", 75, 50);
        Bureaucrat bureaucrat("Charlie", 75);

        std::cout << "Form requiring grade 75: " << form << std::endl;
        std::cout << "Bureaucrat with grade 75: " << bureaucrat << std::endl;

        form.beSigned(bureaucrat);
    } catch (const std::exception& e) {
        std::cout << "Exception when bureaucrat grade equals required grade: " << e.what() << std::endl;
    }

    std::cout << "\n8b. Testing Form signing - bureaucrat better than required grade:" << std::endl;
    try {
        Form form("Better Grade Form", 75, 50);
        Bureaucrat bureaucrat("Diana", 70);

        std::cout << "Form requiring grade 75: " << form << std::endl;
        std::cout << "Bureaucrat with grade 70: " << bureaucrat << std::endl;

        form.beSigned(bureaucrat);
        std::cout << "After signing: " << form << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n9. Testing Form signing - already signed:" << std::endl;
    try {
        Form form("Already Signed Form", 100, 80);
        Bureaucrat bureaucrat1("Dave", 50);
        Bureaucrat bureaucrat2("Eve", 60);

        form.beSigned(bureaucrat1);
        std::cout << "First signing: " << form << std::endl;

        form.beSigned(bureaucrat2);
        std::cout << "Second signing: " << form << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n10. Testing Bureaucrat.signForm() - successful signing:" << std::endl;
    try {
        Form form("Contract Form", 50, 30);
        Bureaucrat bureaucrat("John", 40);

        std::cout << "Before signing: " << form << std::endl;
        std::cout << "Bureaucrat: " << bureaucrat << std::endl;

        bureaucrat.signForm(form);
        std::cout << "After signing: " << form << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n11. Testing Bureaucrat.signForm() - grade too low:" << std::endl;
    try {
        Form form("Top Secret Form", 10, 5);
        Bureaucrat bureaucrat("Jane", 50);

        std::cout << "Form: " << form << std::endl;
        std::cout << "Bureaucrat: " << bureaucrat << std::endl;

        bureaucrat.signForm(form);
        std::cout << "Form after attempt: " << form << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n12. Testing Bureaucrat.signForm() - exactly at required grade:" << std::endl;
    try {
        Form form("Exact Grade Form", 75, 50);
        Bureaucrat bureaucrat("Mike", 75);

        std::cout << "Form: " << form << std::endl;
        std::cout << "Bureaucrat: " << bureaucrat << std::endl;

        bureaucrat.signForm(form);
        std::cout << "Form after signing: " << form << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n13. Testing Bureaucrat.signForm() - already signed form:" << std::endl;
    try {
        Form form("Pre-signed Form", 100, 80);
        Bureaucrat bureaucrat1("Alice", 50);
        Bureaucrat bureaucrat2("Bob", 60);

        std::cout << "Initial form: " << form << std::endl;

        bureaucrat1.signForm(form);
        std::cout << "After first signing: " << form << std::endl;

        bureaucrat2.signForm(form);
        std::cout << "After second attempt: " << form << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== All Form and Bureaucrat.signForm() tests completed ===" << std::endl;

    return 0;
}
