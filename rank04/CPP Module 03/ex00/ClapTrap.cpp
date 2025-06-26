#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() :
    hit_points_(10),
    energy_points_(10),
    attack_damage_(0)
{
    this->name_ = "Noname";
    std::cout << "Default constructor: "
        << GREEN << this->name_ << " was spawned." << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
    name_(name),
    hit_points_(10),
    energy_points_(10),
    attack_damage_(0)
{
    std::cout << "Constructor (with parameters): "
        << GREEN << this->name_ << " was spawned." << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) :
    name_(other.name_),
    hit_points_(other.hit_points_),
    energy_points_(other.energy_points_),
    attack_damage_(other.attack_damage_)
{
    std::cout << "Copy constructor: "
        << GREEN << this->name_ << " was spawned." << RESET << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor: "
    << RED << this->name_ << " was Despawned." << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        name_ = other.name_;
        hit_points_ = other.hit_points_;
        energy_points_ = other.energy_points_;
        attack_damage_ = other.attack_damage_;
    }
    return *this;
}


std::string ClapTrap::getName() const {
    return this->name_;
}

unsigned int ClapTrap::getHitPoints() const {
    return this->hit_points_;
}

unsigned int ClapTrap::getEnergyPoints() const {
    return this->energy_points_;
}

unsigned int ClapTrap::getAttackDamage_() const {
    return this->attack_damage_;
}

void ClapTrap::setName(const std::string& name) {
    this->name_ = name;
}

void ClapTrap::setHitPoints(const unsigned int& hit_points) {
    this->hit_points_ = hit_points;
}

void ClapTrap::setEnergyPoints(const unsigned int& energy_points) {
    this->energy_points_ = energy_points;
}

void ClapTrap::setAttackDamage(const unsigned int& attack_damage) {
    this->attack_damage_ = attack_damage;
}


void ClapTrap::attack(const std::string& target) {
    if (this->isDead() || this->isOutOfEnergy()) {
        std::cout
            << YELLOW << "ClapTrap " << this->name_
            << " does not have any hit point or enough energy to attack!" << RESET << std::endl;
    } else {
        std::cout
            << GREEN << "ClapTrap " << this->name_ << " attacks " << target << ", causing "
            << this->attack_damage_ << " points of damage!" << RESET << std::endl;
        this->energy_points_ -= ClapTrap::kEnergyCost;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout
            << RED << "ClapTrap " << this->name_ << " take " << amount
            << " points of damage!" << RESET << std::endl;
    if (amount >= this->hit_points_) {
        std::cout
            << RED << "ClapTrap " << this->name_ << " is now dead! "
            << RESET << std::endl;
        this->hit_points_ = 0;
    } else {
        this->hit_points_ -= amount;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->isDead() || this->isOutOfEnergy()) {
        std::cout
            << YELLOW << "ClapTrap " << this->name_
            << " does not have any hit point or enough energy to be repaired!" << RESET << std::endl;
    } else {
        std::cout
            << GREEN << "ClapTrap " << this->name_ << " is repaired of " << amount
            << " points of energy!" << RESET << std::endl;
        this->energy_points_ -= ClapTrap::kEnergyCost;
    }
}

bool ClapTrap::isDead() const {
    return this->hit_points_ == 0;
}

bool ClapTrap::isOutOfEnergy() const {
    return this->energy_points_ < ClapTrap::kEnergyCost;
}
