#include "ClapTrap.hpp"
#include <iostream>

int main() {
    std::cout << "=== ClapTrap Testing ===" << std::endl;

    // Test default constructor
    std::cout << "\n--- Testing Default Constructor ---" << std::endl;
    ClapTrap defaultBot;
    std::cout << "Default bot name: " << defaultBot.getName() << std::endl;
    std::cout << "Default bot HP: " << defaultBot.getHitPoints() << std::endl;
    std::cout << "Default bot EP: " << defaultBot.getEnergyPoints() << std::endl;
    std::cout << "Default bot attack damage: " << defaultBot.getAttackDamage() << std::endl;

    // Test parameterized constructor
    std::cout << "\n--- Testing Parameterized Constructor ---" << std::endl;
    ClapTrap jonathan("Jonathan Joestar");
    std::cout << "Jonathan's name: " << jonathan.getName() << std::endl;
    std::cout << "Jonathan's HP: " << jonathan.getHitPoints() << std::endl;
    std::cout << "Jonathan's EP: " << jonathan.getEnergyPoints() << std::endl;
    std::cout << "Jonathan's attack damage: " << jonathan.getAttackDamage() << std::endl;

    // Test copy constructor
    std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
    ClapTrap jojo(jonathan);
    std::cout << "Copy's name: " << jojo.getName() << std::endl;

    // Test assignment operator
    std::cout << "\n--- Testing Assignment Operator ---" << std::endl;
    ClapTrap dio("Dio Brando");
    dio = jonathan;
    std::cout << "Dio after assignment: " << dio.getName() << std::endl;

    // Test attack functionality
    std::cout << "\n--- Testing Attack ---" << std::endl;
    std::cout << "Energy before attack: " << jojo.getEnergyPoints() << std::endl;
    jojo.attack("Dio");
    std::cout << "Energy after attack: " << jojo.getEnergyPoints() << std::endl;

    // Test taking damage
    std::cout << "\n--- Testing Take Damage ---" << std::endl;
    std::cout << "HP before damage: " << jojo.getHitPoints() << std::endl;
    jojo.takeDamage(5);
    std::cout << "HP after taking 5 damage: " << jojo.getHitPoints() << std::endl;

    // Test repair
    std::cout << "\n--- Testing Repair ---" << std::endl;
    std::cout << "HP before repair: " << jojo.getHitPoints() << std::endl;
    std::cout << "EP before repair: " << jojo.getEnergyPoints() << std::endl;
    jojo.beRepaired(3);
    std::cout << "HP after repair: " << jojo.getHitPoints() << std::endl;
    std::cout << "EP after repair: " << jojo.getEnergyPoints() << std::endl;

    // Test edge cases
    std::cout << "\n--- Testing Edge Cases ---" << std::endl;

    // Test zero damage
    jojo.takeDamage(0);

    // Test excessive damage
    std::cout << "HP before excessive damage: " << jojo.getHitPoints() << std::endl;
    jojo.takeDamage(100);
    std::cout << "HP after excessive damage: " << jojo.getHitPoints() << std::endl;
    std::cout << "Is dead: " << (jojo.isDead() ? "Yes" : "No") << std::endl;

    // Test actions when dead
    std::cout << "\n--- Testing Actions When Dead ---" << std::endl;
    jojo.attack("Someone");
    jojo.beRepaired(5);

    // Test energy depletion
    std::cout << "\n--- Testing Energy Depletion ---" << std::endl;
    ClapTrap energyTest("EnergyTester");
    energyTest.setEnergyPoints(2);
    std::cout << "Starting energy: " << energyTest.getEnergyPoints() << std::endl;

    energyTest.attack("Target1");
    energyTest.attack("Target2");
    energyTest.attack("Target3");  // Should fail - no energy

    std::cout << "Final energy: " << energyTest.getEnergyPoints() << std::endl;
    std::cout << "Is out of energy: " << (energyTest.isOutOfEnergy() ? "Yes" : "No") << std::endl;

    std::cout << "\n=== Testing Complete ===" << std::endl;

    return 0;
}
