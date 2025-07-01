#include "../include/Bureaucrat.hpp"
#include <iostream>

int main() {

    std::cout << "\n1. Testing basic constructors:" << std::endl;
    try {
        Bureaucrat b1;
        std::cout << "Default constructor: " << b1 << std::endl;

        Bureaucrat b2("Alice");
        std::cout << "Name constructor: " << b2 << std::endl;

        Bureaucrat b3("Bob", 75);
        std::cout << "Name and grade constructor: " << b3 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n2. Testing grade validation in constructors:" << std::endl;
    try {
        Bureaucrat highGrade("Charlie", 1);
        std::cout << "Valid highest grade: " << highGrade << std::endl;

        Bureaucrat lowGrade("Dave", 150);
        std::cout << "Valid lowest grade: " << lowGrade << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n3. Testing invalid grades in constructors:" << std::endl;
    try {
        Bureaucrat tooHigh("Invalid", 0);
    } catch (const std::exception& e) {
        std::cout << "Grade 0 exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat tooLow("Invalid", 151);
    } catch (const std::exception& e) {
        std::cout << "Grade 151 exception: " << e.what() << std::endl;
    }

    std::cout << "\n4. Testing copy constructor and assignment:" << std::endl;
    try {
        Bureaucrat original("Eve", 50);
        std::cout << "Original: " << original << std::endl;

        Bureaucrat copy(original);
        std::cout << "Copy constructor: " << copy << std::endl;

        Bureaucrat assigned("Frank", 100);
        assigned = original;
        std::cout << "Assignment operator: " << assigned << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n5. Testing grade increment:" << std::endl;
    try {
        Bureaucrat b("Grace", 5);
        std::cout << "Before increment: " << b << std::endl;

        b.incrementGrade();
        std::cout << "After increment: " << b << std::endl;

        b.incrementGrade();
        std::cout << "After second increment: " << b << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n6. Testing grade decrement:" << std::endl;
    try {
        Bureaucrat b("Henry", 148);
        std::cout << "Before decrement: " << b << std::endl;

        b.decrementGrade();
        std::cout << "After decrement: " << b << std::endl;

        b.decrementGrade();
        std::cout << "After second decrement: " << b << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n7. Testing increment at highest grade:" << std::endl;
    try {
        Bureaucrat b("TopLevel", 1);
        std::cout << "At highest grade: " << b << std::endl;

        b.incrementGrade();
        std::cout << "This should not print" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception when incrementing at grade 1: " << e.what() << std::endl;
    }

    std::cout << "\n8. Testing decrement at lowest grade:" << std::endl;
    try {
        Bureaucrat b("BottomLevel", 150);
        std::cout << "At lowest grade: " << b << std::endl;

        b.decrementGrade();
        std::cout << "This should not print" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception when decrementing at grade 150: " << e.what() << std::endl;
    }

    std::cout << "\n9. Testing getters:" << std::endl;
    try {
        Bureaucrat b("Iris", 42);
        std::cout << "Name: " << b.getName() << std::endl;
        std::cout << "Grade: " << b.getGrade() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== All tests completed ===" << std::endl;

    return 0;
}
