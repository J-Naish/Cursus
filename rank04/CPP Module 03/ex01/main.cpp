#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    std::cout << "=== ScavTrap Testing ===" << std::endl;

    // Test default constructor
    std::cout << "\n--- Testing Default Constructor ---" << std::endl;
    ScavTrap defaultBot;
    std::cout << "Default bot name: " << defaultBot.getName() << std::endl;
    std::cout << "Default bot HP: " << defaultBot.getHitPoints() << std::endl;
    std::cout << "Default bot EP: " << defaultBot.getEnergyPoints() << std::endl;
    std::cout << "Default bot attack damage: " << defaultBot.getAttackDamage() << std::endl;

    // Test parameterized constructor
    std::cout << "\n--- Testing Parameterized Constructor ---" << std::endl;
    ScavTrap zepeli("Zepeli");
    std::cout << "Zepeli's name: " << zepeli.getName() << std::endl;
    std::cout << "Zepeli's HP: " << zepeli.getHitPoints() << std::endl;
    std::cout << "Zepeli's EP: " << zepeli.getEnergyPoints() << std::endl;
    std::cout << "Zepeli's attack damage: " << zepeli.getAttackDamage() << std::endl;

    // Test copy constructor
    std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
    ScavTrap zepeli_copy(zepeli);
    std::cout << "Copy's name: " << zepeli_copy.getName() << std::endl;

    // Test assignment operator
    std::cout << "\n--- Testing Assignment Operator ---" << std::endl;
    ScavTrap dio("Dio Brando");
    dio = zepeli;
    std::cout << "Dio after assignment: " << dio.getName() << std::endl;

    // Test ScavTrap specific functionality
    std::cout << "\n--- Testing ScavTrap Specific Functions ---" << std::endl;
    zepeli.guardGate();

    // Test attack functionality (should use ScavTrap's attack)
    std::cout << "\n--- Testing Attack ---" << std::endl;
    std::cout << "Energy before attack: " << zepeli.getEnergyPoints() << std::endl;
    zepeli.attack("Dio");
    std::cout << "Energy after attack: " << zepeli.getEnergyPoints() << std::endl;

    // Test taking damage
    std::cout << "\n--- Testing Take Damage ---" << std::endl;
    std::cout << "HP before damage: " << zepeli.getHitPoints() << std::endl;
    zepeli.takeDamage(20);
    std::cout << "HP after taking 20 damage: " << zepeli.getHitPoints() << std::endl;

    // Test repair
    std::cout << "\n--- Testing Repair ---" << std::endl;
    std::cout << "HP before repair: " << zepeli.getHitPoints() << std::endl;
    std::cout << "EP before repair: " << zepeli.getEnergyPoints() << std::endl;
    zepeli.beRepaired(15);
    std::cout << "HP after repair: " << zepeli.getHitPoints() << std::endl;
    std::cout << "EP after repair: " << zepeli.getEnergyPoints() << std::endl;

    // Test edge cases
    std::cout << "\n--- Testing Edge Cases ---" << std::endl;

    // Test zero damage
    zepeli.takeDamage(0);

    // Test excessive damage
    std::cout << "HP before excessive damage: " << zepeli.getHitPoints() << std::endl;
    zepeli.takeDamage(200);
    std::cout << "HP after excessive damage: " << zepeli.getHitPoints() << std::endl;
    std::cout << "Is dead: " << (zepeli.isDead() ? "Yes" : "No") << std::endl;

    // Test actions when dead
    std::cout << "\n--- Testing Actions When Dead ---" << std::endl;
    zepeli.attack("Someone");
    zepeli.beRepaired(5);
    zepeli.guardGate();

    // Test energy depletion
    std::cout << "\n--- Testing Energy Depletion ---" << std::endl;
    ScavTrap energyTest("EnergyTester");
    energyTest.setEnergyPoints(2);
    std::cout << "Starting energy: " << energyTest.getEnergyPoints() << std::endl;

    energyTest.attack("Target1");
    energyTest.attack("Target2");
    energyTest.attack("Target3");  // Should fail - no energy

    std::cout << "Final energy: " << energyTest.getEnergyPoints() << std::endl;
    std::cout << "Is out of energy: " << (energyTest.isOutOfEnergy() ? "Yes" : "No") << std::endl;

    // Test guardGate with no energy
    std::cout << "\n--- Testing guardGate with no energy ---" << std::endl;
    energyTest.guardGate();

    std::cout << "\n=== Testing Complete ===" << std::endl;

    return 0;
}
