#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Testing AMateria, Ice, and Cure ===" << std::endl;

    Ice* ice = new Ice();
    Cure* cure = new Cure();

    std::cout << "Ice type: " << ice->getType() << std::endl;
    std::cout << "Cure type: " << cure->getType() << std::endl;

    AMateria* iceClone = ice->clone();
    AMateria* cureClone = cure->clone();
    std::cout << "Ice clone type: " << iceClone->getType() << std::endl;
    std::cout << "Cure clone type: " << cureClone->getType() << std::endl;

    delete ice;
    delete cure;
    delete iceClone;
    delete cureClone;

    std::cout << "\n=== Testing Character ===" << std::endl;

    Character alice("Alice");
    Character bob("Bob");
    std::cout << "Character names: " << alice.getName() << " and " << bob.getName() << std::endl;

    alice.equip(new Ice());
    alice.equip(new Cure());
    alice.equip(new Ice());
    alice.equip(new Cure());
    alice.equip(new Ice());

    std::cout << "Alice using materias on Bob:" << std::endl;
    alice.use(0, bob);
    alice.use(1, bob);
    alice.use(2, bob);
    alice.use(3, bob);
    alice.use(4, bob);
    alice.use(-1, bob);

    std::cout << "\nTesting unequip:" << std::endl;
    alice.unequip(1);
    alice.use(1, bob);
    alice.unequip(10);
    alice.unequip(-1);

    Character charlie = alice;
    std::cout << "Copy constructor test - Charlie's name: " << charlie.getName() << std::endl;
    charlie.use(0, bob);

    std::cout << "\n=== Testing MateriaSource ===" << std::endl;

    MateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());

    AMateria* tmp;
    tmp = src->createMateria("ice");
    if (tmp) {
        std::cout << "Created materia: " << tmp->getType() << std::endl;
        delete tmp;
    }

    tmp = src->createMateria("cure");
    if (tmp) {
        std::cout << "Created materia: " << tmp->getType() << std::endl;
        delete tmp;
    }

    tmp = src->createMateria("fire");
    if (!tmp) {
        std::cout << "Failed to create unknown materia type 'fire'" << std::endl;
    }

    MateriaSource srcCopy = *src;
    tmp = srcCopy.createMateria("ice");
    if (tmp) {
        std::cout << "Copy test - Created materia: " << tmp->getType() << std::endl;
        delete tmp;
    }

    delete src;

    std::cout << "\n=== Complete Integration Test ===" << std::endl;

    IMateriaSource* materiaSource = new MateriaSource();
    materiaSource->learnMateria(new Ice());
    materiaSource->learnMateria(new Cure());

    ICharacter* hero = new Character("Hero");
    ICharacter* enemy = new Character("Enemy");

    AMateria* materia1 = materiaSource->createMateria("ice");
    AMateria* materia2 = materiaSource->createMateria("cure");

    hero->equip(materia1);
    hero->equip(materia2);

    std::cout << "Hero (" << hero->getName() << ") battles Enemy (" << enemy->getName() << "):" << std::endl;
    hero->use(0, *enemy);
    hero->use(1, *enemy);

    delete enemy;
    delete hero;
    delete materiaSource;

    std::cout << "\n=== All tests completed ===" << std::endl;

    return 0;
}