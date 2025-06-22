#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    static const int max_contacts = 8;
    Contact contacts[max_contacts];
    int current_contact_count;

public:

    PhoneBook();

    ~PhoneBook();

};


#endif