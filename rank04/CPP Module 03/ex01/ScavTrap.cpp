#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    this->name_ = "Noname";
    this->hit_points_ = kDefaultHitPoints;
    this->energy_points_ = kDefaultEnergyPoints;
    this->attack_damage_ = kDefaultAttackDamage;
    std::cout << "[ScavTrap]Default constructor: "
        << GREEN << this->name_ << " was spawned." << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->name_ = name;
    this->hit_points_ = kDefaultHitPoints;
    this->energy_points_ = kDefaultEnergyPoints;
    this->attack_damage_ = kDefaultAttackDamage;
    std::cout << "[ScavTrap]Constructor (with parameters): "
        << GREEN << this->name_ << " was spawned." << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other) {
  *this = other;
  std::cout << "[ScavTrap]Copy constructor: "
      << GREEN << this->name_ << " was spawned." << RESET << std::endl;
}

ScavTrap::~ScavTrap() {
  std::cout << "[ScavTrap]Destructor: "
  << RED << this->name_ << " was Despawned." << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
  std::cout << "[ScavTrap]Copy assignment operator called" << std::endl;
  if (this != &other) {
      name_ = other.name_;
      hit_points_ = other.hit_points_;
      energy_points_ = other.energy_points_;
      attack_damage_ = other.attack_damage_;
  }
  return *this;
}

void ScavTrap::attack(const std::string& target) {
  if (this->isDead() || this->isOutOfEnergy()) {
      std::cout
          << YELLOW << "ScavTrap " << this->name_
          << " does not have any hit point or enough energy to attack!" << RESET << std::endl;
  } else {
      std::cout
          << GREEN << "ScavTrap " << this->name_ << " attacks " << target << ", causing "
          << this->attack_damage_ << " points of damage!" << RESET << std::endl;
      this->energy_points_ -= ScavTrap::kEnergyCost;
  }
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->name_
        << " is now in Gate keeper mode." << std::endl;
}
