#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "main.hpp"

class Contact {
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

public:
    Contact();
    ~Contact();

    const std::string get_first_name() const;
    const std::string get_last_name() const;
    const std::string get_nickname() const;
    const std::string get_phone_number() const;
    const std::string get_darkest_secret() const;

    void set_first_name(const std::string& first_name);
    void set_last_name(const std::string& last_name);
    void set_nickname(const std::string& nickname);
    void set_phone_number(const std::string& phone_number);
    void set_darkest_secret(const std::string& darkest_secret);

    void update_contact(const std::string& first_name, const std::string& last_name,
        const std::string& nickname, const std::string& phone_number, const std::string& darkest_secret);
};

#endif