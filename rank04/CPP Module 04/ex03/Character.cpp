#include "Character.hpp"


Character::Character() {
    this->name_ = "Noname";
    this->num_occupied_slots_ = 0;
    for (int i = 0; i < kNumSlot; i++) {
        this->inventory_[i] = NULL;
    }
}

Character::Character(std::string name) {
    this->name_ = name;
    this->num_occupied_slots_ = 0;
    for (int i = 0; i < kNumSlot; i++) {
        this->inventory_[i] = NULL;
    }
}

Character::Character(const Character& other) {
    this->name_ = other.getName();
    this->num_occupied_slots_ = other.num_occupied_slots_;
    for (int i = 0; i < kNumSlot; i++) {
        if (other.inventory_[i]) {
            this->inventory_[i] = other.inventory_[i]->clone();
        } else {
            this->inventory_[i] = NULL;
        }
    }
}

Character::~Character() {
    for (int i = 0; i < kNumSlot; i++) {
        if (this->inventory_[i]) {
            delete this->inventory_[i];
        }
    }
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        this->name_ = other.getName();
        this->num_occupied_slots_ = other.num_occupied_slots_;
        for (int i = 0; i < kNumSlot; i++) {
            if (this->inventory_[i]) {
                delete this->inventory_[i];
            }
            if (other.inventory_[i]) {
                this->inventory_[i] = other.inventory_[i]->clone();
            } else {
                this->inventory_[i] = NULL;
            }
        }
    }
    return *this;
}


std::string const & Character::getName() const {
    return this->name_;
}

void Character::equip(AMateria* m) {
    if (!m) {
        return;
    }
    if (this->num_occupied_slots_ >= kNumSlot) {
        std::cout << "The inventory is filled" << std::endl;
        delete m;
        return;
    }
    for (int i = 0; i < kNumSlot; i++) {
        if (!this->inventory_[i]) {
            this->inventory_[i] = m;
            this->num_occupied_slots_++;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (this->num_occupied_slots_ == 0) {
        std::cout << "No Materia is equipped" << std::endl;
        return;
    }
    if (idx >= kNumSlot || idx < 0) {
        std::cerr << "invalid index of the slot:" << idx << std::endl;
        return;
    }
    if (!this->inventory_[idx]) {
        std::cout << "No Materia is equipped at the slot " << idx << std::endl;
        return;
    }
    delete this->inventory_[idx];
    this->inventory_[idx] = NULL;
    num_occupied_slots_--;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= kNumSlot) {
        std::cerr << "index is out of range" << std::endl;
        return;
    }
    if (!inventory_[idx]) {
        std::cout << "There is no Materia at the slot " << idx << std::endl;
        return;
    }
    inventory_[idx]->use(target);
}
