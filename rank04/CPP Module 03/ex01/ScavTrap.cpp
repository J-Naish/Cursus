#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    this->name_ = "Noname";
    this->hit_points_ = 100;
    this->energy_points_ = 50;
    this->attack_damage_ = 20;
    std::cout << "ScavTrap Default constructor: "
        << GREEN << this->name_ << " was spawned." << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
    this->name_ = name;
    this->hit_points_ = 100;
    this->energy_points_ = 50;
    this->attack_damage_ = 20;
    std::cout << "ScavTrap Constructor (with parameters): "
        << GREEN << this->name_ << " was spawned." << RESET << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->name_
        << " is now in Gate keeper mode." << std::endl;
}
