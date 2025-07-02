#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Intern.hpp"
#include <iostream>

int main() {

    std::cout << "\n=== TESTING INTERN CLASS ===" << std::endl;

    std::cout << "\n1. Testing Intern constructors:" << std::endl;
    try {
        Intern intern1;
        std::cout << "Default constructor successful" << std::endl;

        Intern intern2(intern1);
        std::cout << "Copy constructor successful" << std::endl;

        Intern intern3;
        intern3 = intern1;
        std::cout << "Assignment operator successful" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n2. Testing makeForm() - ShrubberyCreationForm:" << std::endl;
    try {
        Intern intern;
        AForm* form = intern.makeForm("ShrubberyCreationForm", "garden");
        if (form) {
            std::cout << "Form created: " << *form << std::endl;
            delete form;
        } else {
            std::cout << "Form creation failed" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n3. Testing makeForm() - RobotomyRequestForm:" << std::endl;
    try {
        Intern intern;
        AForm* form = intern.makeForm("RobotomyRequestForm", "target1");
        if (form) {
            std::cout << "Form created: " << *form << std::endl;
            delete form;
        } else {
            std::cout << "Form creation failed" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n4. Testing makeForm() - PresidentialPardonForm:" << std::endl;
    try {
        Intern intern;
        AForm* form = intern.makeForm("PresidentialPardonForm", "criminal");
        if (form) {
            std::cout << "Form created: " << *form << std::endl;
            delete form;
        } else {
            std::cout << "Form creation failed" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n5. Testing makeForm() - Invalid form name:" << std::endl;
    try {
        Intern intern;
        AForm* form = intern.makeForm("InvalidForm", "target");
        if (form) {
            std::cout << "Form created: " << *form << std::endl;
            delete form;
        } else {
            std::cout << "Form creation failed as expected" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n6. Testing makeForm() - Empty form name:" << std::endl;
    try {
        Intern intern;
        AForm* form = intern.makeForm("", "target");
        if (form) {
            std::cout << "Form created: " << *form << std::endl;
            delete form;
        } else {
            std::cout << "Form creation failed as expected" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n7. Testing makeForm() with created forms - Sign and Execute:" << std::endl;
    try {
        Intern intern;
        Bureaucrat highGrade("Boss", 1);
        
        AForm* shrub = intern.makeForm("ShrubberyCreationForm", "office");
        AForm* robot = intern.makeForm("RobotomyRequestForm", "worker");
        AForm* pardon = intern.makeForm("PresidentialPardonForm", "prisoner");

        if (shrub && robot && pardon) {
            std::cout << "All forms created successfully" << std::endl;
            
            highGrade.signForm(*shrub);
            highGrade.signForm(*robot);
            highGrade.signForm(*pardon);
            
            std::cout << "Forms after signing:" << std::endl;
            std::cout << *shrub << std::endl;
            std::cout << *robot << std::endl;
            std::cout << *pardon << std::endl;
            
            highGrade.executeForm(*shrub);
            highGrade.executeForm(*robot);
            highGrade.executeForm(*pardon);
            
            delete shrub;
            delete robot;
            delete pardon;
        }
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n8. Testing makeForm() - Case sensitivity:" << std::endl;
    try {
        Intern intern;
        AForm* form1 = intern.makeForm("shrubberyCreationForm", "test");
        AForm* form2 = intern.makeForm("SHRUBBERYCREATIONFORM", "test");
        
        if (!form1 && !form2) {
            std::cout << "Case sensitivity handled correctly - both failed as expected" << std::endl;
        } else {
            if (form1) delete form1;
            if (form2) delete form2;
            std::cout << "Case sensitivity not handled correctly" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== All Intern tests completed ===" << std::endl;

    return 0;
}
