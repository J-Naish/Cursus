#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

const std::string Contact::get_first_name() const {
    return this->first_name;
}

const std::string Contact::get_last_name() const {
    return this->last_name;
}

const std::string Contact::get_nickname() const {
    return this->nickname;
}

const std::string Contact::get_phone_number() const {
    return this->phone_number;
}

const std::string Contact::get_darkest_secret() const {
    return this->darkest_secret;
}

void Contact::set_first_name(const std::string& first_name) {
    this->first_name = first_name;
}

void Contact::set_last_name(const std::string& last_name) {
    this->last_name = last_name;
}

void Contact::set_nickname(const std::string& nickname) {
    this->nickname = nickname;
}

void Contact::set_phone_number(const std::string& phone_number) {
    this->phone_number = phone_number;
}

void Contact::set_darkest_secret(const std::string& darkest_secret) {
    this->darkest_secret = darkest_secret;
}

void Contact::update_contact(
    const std::string& first_name,
    const std::string& last_name,
    const std::string& nickname,
    const std::string& phone_number,
    const std::string& darkest_secret)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->nickname = nickname;
    this->phone_number = phone_number;
    this->darkest_secret = darkest_secret;
}
