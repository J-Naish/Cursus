#include "Character.hpp"


Character::Character() {
    this->name_ = "Noname";
    this->occupied_slot_ = 0;
    for (int i = 0; i < kNumSlot; i++) {
        this->inventory[i] = nullptr;
    }
}

Character::Character(std::string name) {
    this->name_ = name;
    this->occupied_slot_ = 0;
    for (int i = 0; i < kNumSlot; i++) {
        this->inventory[i] = nullptr;
    }
}

Character::Character(const Character& other) {
    *this = other;
}

Character::~Character() {
    for (int i = 0; i < kNumSlot; i++) {
        if (this->inventory[i]) {
            delete this->inventory[i];
        }
    }
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        this->name_ = other.getName();
        this->occupied_slot_ = other.occupied_slot_;
        for (int i = 0; i < kNumSlot; i++) {
            if (this->inventory[i]) {
                delete this->inventory[i];
            }
            this->inventory[i] = other.inventory[i]->clone();
        }
    }
    return *this;
}


std::string const & Character::getName() const {
    return this->name_;
}

void Character::equip(AMateria* m) {
    if (this->occupied_slot_ >= kNumSlot) {
        std::cout << "The inventory is filled" << std::endl;
        return;
    }
    for (int i = 0; i < kNumSlot; i++) {
        if (!this->inventory[i]) {
            this->inventory[i] = m;
            this->occupied_slot_++;
        }
    }
}

void Character::unequip(int idx) {
    if (this->occupied_slot_ == 0) {
        std::cout << "No Materia is equipped" << std::endl;
        return;
    }
    // 既存のMateriaをどこかに格納しておく
    this->inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target) {
    inventory[idx]->use(target);
}
