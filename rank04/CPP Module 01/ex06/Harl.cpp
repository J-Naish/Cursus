#include "Harl.hpp"

void Harl::debug( void ) {
    std::cout
        << "[ DEBUG ]"
        << std::endl
        << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
        << std::endl;
}

void Harl::info( void ) {
    std::cout
        << "[ INFO ]"
        << std::endl
        << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
        << std::endl;
}

void Harl::warning( void ) {
    std::cout
        << "[ WARNING ]"
        << std::endl
        << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
        << std::endl;
}

void Harl::error( void ) {
    std::cout
        << "[ ERROR ]"
        << std::endl
        << "This is unacceptable! I want to speak to the manager now."
        << std::endl;
}

void Harl::complain( std::string level ) {

    std::string levels[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR",
    };

    int index = -1;

    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            index = i;
            break;
        }
    }

    switch (index)
    {
    case 0:
        this->debug();
        break;
    case 1:
        this->info();
        break;
    case 2:
        this->warning();
        break;
    case 3:
        this->error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }

}
