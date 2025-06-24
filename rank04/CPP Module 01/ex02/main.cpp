#include <iostream>
#include <string>

#define GREEN "\033[32m"
#define RESET "\033[0m"


int main ( void ) {

    std::string string = "HI THIS IS BRAIN";
    std::string* stringPTR = &string;
    std::string& stringREF = string;


    std::cout << "The memory address of the string variable: " << GREEN << &string << RESET << std::endl;
    std::cout << "The memory address held by stringPTR:      " << GREEN << stringPTR << RESET << std::endl;
    std::cout << "The memory address held by stringREF:      " << GREEN << &stringREF << RESET << std::endl;

    std::cout << "The value of the string variable:          " << GREEN << string << RESET << std::endl;
    std::cout << "The value pointed to by stringPTR:         " << GREEN << *stringPTR << RESET << std::endl;
    std::cout << "The value pointed to by stringREF:         " << GREEN << stringREF << RESET << std::endl;

}
