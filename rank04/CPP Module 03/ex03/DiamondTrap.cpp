#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() :
    ClapTrap("Noname_clap_name"),
    ScavTrap("Noname_clap_name"),
    FragTrap("Noname_clap_name"),
    name_("Noname")
{
    this->hit_points_ = FragTrap::kDefaultHitPoints;
    this->energy_points_ = ScavTrap::kDefaultEnergyPoints;
    this->attack_damage_ = FragTrap::kDefaultAttackDamage;

    std::cout << "[DiamondTrap]Default constructor: "
        << GREEN << this->name_ << " was spawned." << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) :
    ClapTrap(name + "_clap_name"),
    ScavTrap(name + "_clap_name"),
    FragTrap(name + "_clap_name"),
    name_(name)
{
    this->hit_points_ = FragTrap::kDefaultHitPoints;
    this->energy_points_ = ScavTrap::kDefaultEnergyPoints;
    this->attack_damage_ = FragTrap::kDefaultAttackDamage;

    std::cout << "[DiamondTrap]Constructor (with parameters): "
        << GREEN << this->name_ << " was spawned." << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :
    ClapTrap(other),
    ScavTrap(other),
    FragTrap(other)
{
    this->name_ = other.name_;
    std::cout << "[DiamondTrap]Copy constructor: "
        << GREEN << this->name_ << " was spawned." << RESET << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "[DiamondTrap]Destructor: "
        << RED << this->name_ << " was Despawned." << RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "[DiamondTrap]Copy assignment operator called" << std::endl;
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
