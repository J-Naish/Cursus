#pragma once
#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "main.hpp"
#include "Contact.hpp"

class PhoneBook {
private:
    static const int max_contacts = 8;
    Contact contacts[max_contacts];
    int current_contact_count;

public:

    PhoneBook();

    ~PhoneBook();

    void add_contact();

    void search_contact() const;
};


#endif