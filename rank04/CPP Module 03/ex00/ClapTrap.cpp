#include "ClapTrap.hpp"


ClapTrap::ClapTrap() :
    hit_points_(10),
    energy_points_(10),
    attack_damage_(0) {}

ClapTrap::ClapTrap(std::string name) :
    name_(name),
    hit_points_(10),
    energy_points_(10),
    attack_damage_(0) {}

ClapTrap::ClapTrap(const ClapTrap& other) :
    name_(other.name_),
    hit_points_(other.hit_points_),
    energy_points_(other.energy_points_),
    attack_damage_(other.attack_damage_) {}

ClapTrap::~ClapTrap() {}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        name_ = other.name_;
        hit_points_ = other.hit_points_;
        energy_points_ = other.energy_points_;
        attack_damage_ = other.attack_damage_;
    }
    return *this;
}



void ClapTrap::attack(const std::string& target) {

}

void ClapTrap::takeDamage(unsigned int amount) {

}

void beRepaired(unsigned int amount) {

}
