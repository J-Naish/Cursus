#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main() {
    std::cout << "=== DiamondTrap Testing ===" << std::endl;

    // Test default constructor
    std::cout << "\n--- Testing Default Constructor ---" << std::endl;
    DiamondTrap defaultBot;
    std::cout << "Default bot name: " << defaultBot.getName() << std::endl;
    std::cout << "Default bot HP: " << defaultBot.getHitPoints() << std::endl;
    std::cout << "Default bot EP: " << defaultBot.getEnergyPoints() << std::endl;
    std::cout << "Default bot attack damage: " << defaultBot.getAttackDamage() << std::endl;
    defaultBot.whoAmI();

    // Test parameterized constructor
    std::cout << "\n--- Testing Parameterized Constructor ---" << std::endl;
    DiamondTrap george("George");
    std::cout << "George's name: " << george.getName() << std::endl;
    std::cout << "George's HP: " << george.getHitPoints() << std::endl;
    std::cout << "George's EP: " << george.getEnergyPoints() << std::endl;
    std::cout << "George's attack damage: " << george.getAttackDamage() << std::endl;
    george.whoAmI();

    // Test copy constructor
    std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
    DiamondTrap george_copy(george);
    std::cout << "Copy's name: " << george_copy.getName() << std::endl;
    george_copy.whoAmI();

    // Test assignment operator
    std::cout << "\n--- Testing Assignment Operator ---" << std::endl;
    DiamondTrap dio("Dio Brando");
    dio = george;
    std::cout << "Dio after assignment: " << dio.getName() << std::endl;
    dio.whoAmI();

    // Test DiamondTrap specific functionality
    std::cout << "\n--- Testing DiamondTrap Specific Functions ---" << std::endl;
    george.whoAmI();

    // Test inherited functions from FragTrap
    std::cout << "\n--- Testing FragTrap Functions ---" << std::endl;
    george.highFivesGuys();

    // Test inherited functions from ScavTrap
    std::cout << "\n--- Testing ScavTrap Functions ---" << std::endl;
    george.guardGate();

    // Test attack functionality (should use ScavTrap's attack)
    std::cout << "\n--- Testing Attack ---" << std::endl;
    std::cout << "Energy before attack: " << george.getEnergyPoints() << std::endl;
    george.attack("cars");
    std::cout << "Energy after attack: " << george.getEnergyPoints() << std::endl;

    // Test taking damage
    std::cout << "\n--- Testing Take Damage ---" << std::endl;
    std::cout << "HP before damage: " << george.getHitPoints() << std::endl;
    george.takeDamage(50);
    std::cout << "HP after taking 50 damage: " << george.getHitPoints() << std::endl;

    // Test repair
    std::cout << "\n--- Testing Repair ---" << std::endl;
    std::cout << "HP before repair: " << george.getHitPoints() << std::endl;
    std::cout << "EP before repair: " << george.getEnergyPoints() << std::endl;
    george.beRepaired(30);
    std::cout << "HP after repair: " << george.getHitPoints() << std::endl;
    std::cout << "EP after repair: " << george.getEnergyPoints() << std::endl;

    // Test edge cases
    std::cout << "\n--- Testing Edge Cases ---" << std::endl;

    // Test zero damage
    george.takeDamage(0);

    // Test excessive damage
    std::cout << "HP before excessive damage: " << george.getHitPoints() << std::endl;
    george.takeDamage(200);
    std::cout << "HP after excessive damage: " << george.getHitPoints() << std::endl;
    std::cout << "Is dead: " << (george.isDead() ? "Yes" : "No") << std::endl;

    // Test actions when dead
    std::cout << "\n--- Testing Actions When Dead ---" << std::endl;
    george.attack("Someone");
    george.beRepaired(5);
    george.whoAmI();
    george.highFivesGuys();
    george.guardGate();

    // Test energy depletion
    std::cout << "\n--- Testing Energy Depletion ---" << std::endl;
    DiamondTrap energyTest("EnergyTester");
    energyTest.setEnergyPoints(2);
    std::cout << "Starting energy: " << energyTest.getEnergyPoints() << std::endl;

    energyTest.attack("Target1");
    energyTest.attack("Target2");
    energyTest.attack("Target3");  // Should fail - no energy

    std::cout << "Final energy: " << energyTest.getEnergyPoints() << std::endl;
    std::cout << "Is out of energy: " << (energyTest.isOutOfEnergy() ? "Yes" : "No") << std::endl;

    // Test special functions with no energy
    std::cout << "\n--- Testing special functions with no energy ---" << std::endl;
    energyTest.whoAmI();
    energyTest.highFivesGuys();
    energyTest.guardGate();

    std::cout << "\n=== Testing Complete ===" << std::endl;

    return 0;
}
