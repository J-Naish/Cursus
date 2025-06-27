#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap() {
    this->name_ = "Noname";
    this->hit_points_ = 100;
    this->energy_points_ = 100;
    this->attack_damage_ = 30;
    std::cout << "FragTrap Default constructor: "
        << GREEN << this->name_ << " was spawned." << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->name_ = name;
    this->hit_points_ = 100;
    this->energy_points_ = 100;
    this->attack_damage_ = 30;
    std::cout << "FragTrap Constructor (with parameters): "
        << GREEN << this->name_ << " was spawned." << RESET << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor: "
        << RED << this->name_ << " was Despawned." << RESET << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "Give me a 🤚?" << std::endl;
}
