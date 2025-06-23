#include "PhoneBook.hpp"
#include <limits>

PhoneBook::PhoneBook() : current_contact_count(0) {}

PhoneBook::~PhoneBook() {}

static bool is_valid_phone_number(std::string phone_number) {
    if (phone_number.empty()) {
        return false;
    }

    for (size_t i = 0; i < phone_number.length(); i++) {
        if (!isdigit(phone_number[i]) && phone_number[i] != '-') {
            return false;
        }
    }

    return true;
}

void PhoneBook::add_contact() {

    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;


    std::cout << "first name> ";
    std::getline(std::cin, first_name);

    std::cout << "last name> ";
    std::getline(std::cin, last_name);

    std::cout << "nickname> ";
    std::getline(std::cin, nickname);

    std::cout << "phone number> ";
    std::getline(std::cin, phone_number);
    if (!is_valid_phone_number(phone_number)) {
        std::cout << RED << "invalid phone number. enter phone number again> " << RESET;
        std::getline(std::cin, phone_number);
    }

    std::cout << "darkest secret> ";
    std::getline(std::cin, darkest_secret);

    if (current_contact_count >= max_contacts) {

        for (int i = 0; i < max_contacts - 1; i++) {
            contacts[i] = contacts[i + 1];
        }

        contacts[max_contacts - 1]
            .update_contact(first_name, last_name, nickname, phone_number, darkest_secret);

    } else {

        contacts[current_contact_count]
            .update_contact(first_name, last_name, nickname, phone_number, darkest_secret);

        current_contact_count++;

    }
}



static const std::string truncate(std::string str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    } else if (str.length() < 10) {
        return std::string(10 - str.length(), ' ') + str;
    } else {
        return str;
    }
}

static std::string intToString(int number) {
    std::stringstream ss;
    ss << number;
    return ss.str();
}


void PhoneBook::search_contact() const {

    std::cout << "     index" << "|";
    std::cout << "first name" << "|";
    std::cout << " last name" << "|";
    std::cout << "  nickname" << std::endl;

    for (int i = 0; i < current_contact_count; i++) {
        std::cout << truncate(intToString(i + 1)) << "|";
        std::cout << truncate(contacts[i].get_first_name()) << "|";
        std::cout << truncate(contacts[i].get_last_name()) << "|";
        std::cout << truncate(contacts[i].get_nickname()) << std::endl;
    }

    int index;

    std::cout << "enter an index> ";
    std::cin >> index;

    while (std::cin.fail() || index <= 0 || index > current_contact_count) {
        std::cout << RED << "invalid index. please enter an integer again > " << RESET;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> index;
    }

    std::cout << "first name    : " << contacts[index - 1].get_first_name() << std::endl;
    std::cout << "last name     : " << contacts[index - 1].get_last_name() << std::endl;
    std::cout << "nickname      : " << contacts[index - 1].get_nickname() << std::endl;
    std::cout << "phone number  : " << contacts[index - 1].get_phone_number() << std::endl;
    std::cout << "darkest secret: " << contacts[index - 1].get_darkest_secret() << std::endl;

}

