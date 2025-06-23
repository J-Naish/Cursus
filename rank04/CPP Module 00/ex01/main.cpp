#include "main.hpp"
#include "PhoneBook.hpp"

int main() {

    PhoneBook phone_book;

    while (1) {

        std::cout << "enter a command: ADD, SEARCH, or EXIT> ";

        std::string command;
        std::cin >> command;
        std::cin.ignore();

        if (command == "ADD") {
            phone_book.add_contact();
        } else if (command == "SEARCH") {
            phone_book.search_contact();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << RED << "invalid command" << RESET << std::endl;
        }

    }

    return (0);
}
