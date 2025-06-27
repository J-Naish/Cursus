#include "Character.hpp"


Character::Character() {
    this->name_ = "Noname";
    this->num_occupied_slots_ = 0;
    for (int i = 0; i < kNumSlot; i++) {
        this->inventory[i] = nullptr;
    }
}

Character::Character(std::string name) {
    this->name_ = name;
    this->num_occupied_slots_ = 0;
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
        this->num_occupied_slots_ = other.num_occupied_slots_;
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
    if (this->num_occupied_slots_ >= kNumSlot) {
        std::cout << "The inventory is filled" << std::endl;
        return;
    }
    for (int i = 0; i < kNumSlot; i++) {
        if (!this->inventory[i]) {
            this->inventory[i] = m;
            this->num_occupied_slots_++;
        }
    }
}

void Character::unequip(int idx) {
    if (this->num_occupied_slots_ == 0) {
        std::cout << "No Materia is equipped" << std::endl;
        return;
    }
    if (!this->inventory[idx]) {
        std::cout << "No Materia is equipped at the slot " << idx << std::endl;
        return;
    }
    // 既存のMateriaをどこかに格納しておく
    this->inventory[idx] = nullptr;
    num_occupied_slots_--;
}

void Character::use(int idx, ICharacter& target) {
    inventory[idx]->use(target);
}
