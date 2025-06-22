#include "PhoneBook.hpp"
#include <string>
#include <iostream>


PhoneBook::PhoneBook() : current_contact_count(0) {}

PhoneBook::~PhoneBook() {}

static bool is_valid_phone_number(std::string phone_number) {
    if (phone_number.empty()) {
        return false;
    }

    for (char c : phone_number) {
        if (!isdigit(c) && c != '-') {
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


    std::cout << "first name>";
    std::getline(std::cin, first_name);

    std::cout << "last name>";
    std::getline(std::cin, last_name);

    std::cout << "nickname>";
    std::getline(std::cin, nickname);

    std::cout << "phone number>";
    std::getline(std::cin, phone_number);
    if (!is_valid_phone_number(phone_number)) {
        std::cout << "invalid phone number. enter phone number again>";
        std::getline(std::cin, phone_number);
    }

    std::cout << "darkest secret>";
    std::getline(std::cin, darkest_secret);

    if (current_contact_count >= max_contacts) {

        for (int i = 0; i < max_contacts - 1; i++) {
            contacts[i] = contacts[i + 1];
        }

        contacts[max_contacts - 1].set_first_name(first_name);
        contacts[max_contacts - 1].set_last_name(last_name);
        contacts[max_contacts - 1].set_nickname(nickname);
        contacts[max_contacts - 1].set_phone_number(phone_number);
        contacts[max_contacts - 1].set_darkest_secret(darkest_secret);

    } else {

        contacts[current_contact_count].set_first_name(first_name);
        contacts[current_contact_count].set_last_name(last_name);
        contacts[current_contact_count].set_nickname(nickname);
        contacts[current_contact_count].set_phone_number(phone_number);
        contacts[current_contact_count].set_darkest_secret(darkest_secret);

        current_contact_count++;

    }
}


