#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() {
    this->name_ = "Noname";
    this->hit_points_ = FragTrap::hit_points_;
    this->energy_points_ = ScavTrap::energy_points_;
    this->attack_damage_ = FragTrap::attack_damage_;

    std::cout << "Default constructor: "
        << GREEN << this->name_ << " was spawned." << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name") {
    this->name_ = name;
    this->hit_points_ = FragTrap::hit_points_;
    this->energy_points_ = ScavTrap::energy_points_;
    this->attack_damage_ = FragTrap::attack_damage_;

    std::cout << "DiamondTrap Constructor (with parameters): "
        << GREEN << this->name_ << " was spawned." << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :
    ClapTrap(other),
    ScavTrap(other),
    FragTrap(other)
{
    *this = other;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap Destructor: "
        << RED << this->name_ << " was Despawned." << RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
    if (this != &other) {
        name_ = other.name_;
        hit_points_ = other.hit_points_;
        energy_points_ = other.energy_points_;
        attack_damage_ = other.attack_damage_;
    }
    return *this;
}


void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "My DiamondTrap name is " << this->name_
        << ", and ClapTrap name is " << this->ClapTrap::name_ << std::endl;
}
