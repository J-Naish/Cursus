#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include <iostream>

int main() {

    std::cout << "\n=== TESTING CONCRETE FORM CLASSES ===" << std::endl;

    std::cout << "\n1. Testing ShrubberyCreationForm constructors:" << std::endl;
    try {
        ShrubberyCreationForm s1;
        std::cout << "Default constructor: " << s1 << std::endl;

        ShrubberyCreationForm s2("garden");
        std::cout << "Target constructor: " << s2 << std::endl;

        ShrubberyCreationForm s3(s2);
        std::cout << "Copy constructor: " << s3 << std::endl;

        ShrubberyCreationForm s4("backyard");
        s4 = s2;
        std::cout << "Assignment operator: " << s4 << std::endl;
        std::cout << "Target: " << s4.getTarget() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n2. Testing RobotomyRequestForm constructors:" << std::endl;
    try {
        RobotomyRequestForm r1;
        std::cout << "Default constructor: " << r1 << std::endl;

        RobotomyRequestForm r2("Bob");
        std::cout << "Target constructor: " << r2 << std::endl;

        RobotomyRequestForm r3(r2);
        std::cout << "Copy constructor: " << r3 << std::endl;

        RobotomyRequestForm r4("Alice");
        r4 = r2;
        std::cout << "Assignment operator: " << r4 << std::endl;
        std::cout << "Target: " << r4.getTarget() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n3. Testing PresidentialPardonForm constructors:" << std::endl;
    try {
        PresidentialPardonForm p1;
        std::cout << "Default constructor: " << p1 << std::endl;

        PresidentialPardonForm p2("Charlie");
        std::cout << "Target constructor: " << p2 << std::endl;

        PresidentialPardonForm p3(p2);
        std::cout << "Copy constructor: " << p3 << std::endl;

        PresidentialPardonForm p4("David");
        p4 = p2;
        std::cout << "Assignment operator: " << p4 << std::endl;
        std::cout << "Target: " << p4.getTarget() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TESTING FORM EXECUTION ===" << std::endl;

    std::cout << "\n4. Testing ShrubberyCreationForm execution - successful:" << std::endl;
    try {
        ShrubberyCreationForm shrub("home");
        Bureaucrat signer("Signer", 145);
        Bureaucrat executor("Executor", 137);

        std::cout << "Form: " << shrub << std::endl;
        std::cout << "Signer: " << signer << std::endl;
        std::cout << "Executor: " << executor << std::endl;

        signer.signForm(shrub);
        std::cout << "After signing: " << shrub << std::endl;

        executor.executeForm(shrub);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n5. Testing ShrubberyCreationForm execution - unsigned form:" << std::endl;
    try {
        ShrubberyCreationForm shrub("office");
        Bureaucrat executor("Executor", 137);

        std::cout << "Unsigned form: " << shrub << std::endl;
        std::cout << "Executor: " << executor << std::endl;

        executor.executeForm(shrub);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n6. Testing ShrubberyCreationForm execution - grade too low:" << std::endl;
    try {
        ShrubberyCreationForm shrub("park");
        Bureaucrat signer("Signer", 145);
        Bureaucrat executor("Executor", 150);

        signer.signForm(shrub);
        std::cout << "Signed form: " << shrub << std::endl;
        std::cout << "Low grade executor: " << executor << std::endl;

        executor.executeForm(shrub);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n7. Testing RobotomyRequestForm execution - successful:" << std::endl;
    try {
        RobotomyRequestForm robot("TestSubject");
        Bureaucrat signer("Signer", 72);
        Bureaucrat executor("Executor", 45);

        std::cout << "Form: " << robot << std::endl;
        std::cout << "Signer: " << signer << std::endl;
        std::cout << "Executor: " << executor << std::endl;

        signer.signForm(robot);
        std::cout << "After signing: " << robot << std::endl;

        executor.executeForm(robot);
        executor.executeForm(robot);
        executor.executeForm(robot);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n8. Testing RobotomyRequestForm execution - grade too low:" << std::endl;
    try {
        RobotomyRequestForm robot("Patient");
        Bureaucrat signer("Signer", 72);
        Bureaucrat executor("Executor", 50);

        signer.signForm(robot);
        std::cout << "Signed form: " << robot << std::endl;
        std::cout << "Low grade executor: " << executor << std::endl;

        executor.executeForm(robot);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n9. Testing PresidentialPardonForm execution - successful:" << std::endl;
    try {
        PresidentialPardonForm pardon("Criminal");
        Bureaucrat signer("Signer", 25);
        Bureaucrat executor("Executor", 5);

        std::cout << "Form: " << pardon << std::endl;
        std::cout << "Signer: " << signer << std::endl;
        std::cout << "Executor: " << executor << std::endl;

        signer.signForm(pardon);
        std::cout << "After signing: " << pardon << std::endl;

        executor.executeForm(pardon);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n10. Testing PresidentialPardonForm execution - grade too low:" << std::endl;
    try {
        PresidentialPardonForm pardon("Prisoner");
        Bureaucrat signer("Signer", 25);
        Bureaucrat executor("Executor", 10);

        signer.signForm(pardon);
        std::cout << "Signed form: " << pardon << std::endl;
        std::cout << "Low grade executor: " << executor << std::endl;

        executor.executeForm(pardon);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TESTING SIGNING EDGE CASES ===" << std::endl;

    std::cout << "\n11. Testing form signing - grade too low to sign:" << std::endl;
    try {
        PresidentialPardonForm pardon("VIP");
        Bureaucrat lowGradeBureaucrat("LowGrade", 30);

        std::cout << "Form requiring grade 25 to sign: " << pardon << std::endl;
        std::cout << "Bureaucrat with grade 30: " << lowGradeBureaucrat << std::endl;

        lowGradeBureaucrat.signForm(pardon);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n12. Testing multiple forms with same bureaucrat:" << std::endl;
    try {
        Bureaucrat superBureaucrat("SuperBureaucrat", 1);
        ShrubberyCreationForm shrub("yard");
        RobotomyRequestForm robot("Android");
        PresidentialPardonForm pardon("Convict");

        std::cout << "Super bureaucrat: " << superBureaucrat << std::endl;

        superBureaucrat.signForm(shrub);
        superBureaucrat.signForm(robot);
        superBureaucrat.signForm(pardon);

        std::cout << "All forms signed:" << std::endl;
        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;

        superBureaucrat.executeForm(shrub);
        superBureaucrat.executeForm(robot);
        superBureaucrat.executeForm(pardon);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== All tests completed ===" << std::endl;

    return 0;
}
