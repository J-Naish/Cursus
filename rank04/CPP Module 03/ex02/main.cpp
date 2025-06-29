#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
    std::cout << "=== FragTrap Testing ===" << std::endl;

    // Test default constructor
    std::cout << "\n--- Testing Default Constructor ---" << std::endl;
    FragTrap defaultBot;
    std::cout << "Default bot name: " << defaultBot.getName() << std::endl;
    std::cout << "Default bot HP: " << defaultBot.getHitPoints() << std::endl;
    std::cout << "Default bot EP: " << defaultBot.getEnergyPoints() << std::endl;
    std::cout << "Default bot attack damage: " << defaultBot.getAttackDamage() << std::endl;

    // Test parameterized constructor
    std::cout << "\n--- Testing Parameterized Constructor ---" << std::endl;
    FragTrap speedwagon("Speedwagon");
    std::cout << "Speedwagon's name: " << speedwagon.getName() << std::endl;
    std::cout << "Speedwagon's HP: " << speedwagon.getHitPoints() << std::endl;
    std::cout << "Speedwagon's EP: " << speedwagon.getEnergyPoints() << std::endl;
    std::cout << "Speedwagon's attack damage: " << speedwagon.getAttackDamage() << std::endl;

    // Test copy constructor
    std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
    FragTrap speedwagon_copy(speedwagon);
    std::cout << "Copy's name: " << speedwagon_copy.getName() << std::endl;

    // Test assignment operator
    std::cout << "\n--- Testing Assignment Operator ---" << std::endl;
    FragTrap dio("Dio Brando");
    dio = speedwagon;
    std::cout << "Dio after assignment: " << dio.getName() << std::endl;

    // Test FragTrap specific functionality
    std::cout << "\n--- Testing FragTrap Specific Functions ---" << std::endl;
    speedwagon.highFivesGuys();

    // Test attack functionality (should use FragTrap's attack if overridden)
    std::cout << "\n--- Testing Attack ---" << std::endl;
    std::cout << "Energy before attack: " << speedwagon.getEnergyPoints() << std::endl;
    speedwagon.attack("Dio");
    std::cout << "Energy after attack: " << speedwagon.getEnergyPoints() << std::endl;

    // Test taking damage
    std::cout << "\n--- Testing Take Damage ---" << std::endl;
    std::cout << "HP before damage: " << speedwagon.getHitPoints() << std::endl;
    speedwagon.takeDamage(30);
    std::cout << "HP after taking 30 damage: " << speedwagon.getHitPoints() << std::endl;

    // Test repair
    std::cout << "\n--- Testing Repair ---" << std::endl;
    std::cout << "HP before repair: " << speedwagon.getHitPoints() << std::endl;
    std::cout << "EP before repair: " << speedwagon.getEnergyPoints() << std::endl;
    speedwagon.beRepaired(25);
    std::cout << "HP after repair: " << speedwagon.getHitPoints() << std::endl;
    std::cout << "EP after repair: " << speedwagon.getEnergyPoints() << std::endl;

    // Test edge cases
    std::cout << "\n--- Testing Edge Cases ---" << std::endl;

    // Test zero damage
    speedwagon.takeDamage(0);

    // Test excessive damage
    std::cout << "HP before excessive damage: " << speedwagon.getHitPoints() << std::endl;
    speedwagon.takeDamage(200);
    std::cout << "HP after excessive damage: " << speedwagon.getHitPoints() << std::endl;
    std::cout << "Is dead: " << (speedwagon.isDead() ? "Yes" : "No") << std::endl;

    // Test actions when dead
    std::cout << "\n--- Testing Actions When Dead ---" << std::endl;
    speedwagon.attack("Someone");
    speedwagon.beRepaired(5);
    speedwagon.highFivesGuys();

    // Test energy depletion
    std::cout << "\n--- Testing Energy Depletion ---" << std::endl;
    FragTrap energyTest("EnergyTester");
    energyTest.setEnergyPoints(2);
    std::cout << "Starting energy: " << energyTest.getEnergyPoints() << std::endl;

    energyTest.attack("Target1");
    energyTest.attack("Target2");
    energyTest.attack("Target3");  // Should fail - no energy

    std::cout << "Final energy: " << energyTest.getEnergyPoints() << std::endl;
    std::cout << "Is out of energy: " << (energyTest.isOutOfEnergy() ? "Yes" : "No") << std::endl;

    // Test highFivesGuys with no energy
    std::cout << "\n--- Testing highFivesGuys with no energy ---" << std::endl;
    energyTest.highFivesGuys();

    std::cout << "\n=== Testing Complete ===" << std::endl;

    return 0;
}
