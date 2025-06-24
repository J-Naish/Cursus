#include "Harl.hpp"

int main(int argc, char *argv[]) {

    Harl harl = Harl();

    if (argc >= 2) {
        harl.complain(argv[1]);
    } else {
        harl.complain("");
    }

    return 0;
}
