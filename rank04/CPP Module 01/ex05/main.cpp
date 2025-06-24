#include "Harl.hpp"

static void call_complain(Harl harl, std::string level) {

    std::cout << level << ": ";
    harl.complain(level);
    std::cout << std::endl;

}

int main() {

    Harl harl = Harl();

    call_complain(harl, "DEBUG");
    call_complain(harl, "INFO");
    call_complain(harl, "WARNING");
    call_complain(harl, "ERROR");

}
