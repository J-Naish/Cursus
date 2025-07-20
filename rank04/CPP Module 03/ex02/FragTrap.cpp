#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap() {
    this->name_ = "Noname";
    this->hit_points_ = kDefaultHitPoints;
    this->energy_points_ = kDefaultEnergyPoints;
    this->attack_damage_ = kDefaultAttackDamage;
    std::cout << "[FragTrap]Default constructor: "
        << GREEN << this->name_ << " was spawned." << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->name_ = name;
    this->hit_points_ = kDefaultHitPoints;
    this->energy_points_ = kDefaultEnergyPoints;
    this->attack_damage_ = kDefaultAttackDamage;
    std::cout << "[FragTrap]Constructor (with parameters): "
        << GREEN << this->name_ << " was spawned." << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other) {
  std::cout << "[FragTrap]Copy constructor: "
      << GREEN << this->name_ << " was spawned." << RESET << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "[FragTrap]Destructor: "
        << RED << this->name_ << " was Despawned." << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
  std::cout << "[FragTrap]Copy assignment operator called" << std::endl;
  if (this != &other) {
      name_ = other.name_;
      hit_points_ = other.hit_points_;
      energy_points_ = other.energy_points_;
      attack_damage_ = other.attack_damage_;
  }
  return *this;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "Give me a 🤚?" << std::endl;
}
