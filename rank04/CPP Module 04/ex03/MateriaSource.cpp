#include "MateriaSource.hpp"


MateriaSource::MateriaSource() {
    num_memorized = 0;
    for (int i = 0; i < kNumSlot; i++) {
        this->source_[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    *this = other;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < kNumSlot; i++) {
        if (this->source_[i]) {
            delete this->source_[i];
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        this->num_memorized = other.num_memorized;
        for (int i = 0; i < kNumSlot; i++) {
            if (this->source_[i]) {
                delete this->source_[i];
            }
            if (other.source_[i]) {
                this->source_[i] = other.source_[i]->clone();
            } else {
                this->source_[i] = NULL;
            }
        }
    }
    return *this;
}


void MateriaSource::learnMateria(AMateria* m) {
    if (num_memorized >= 4) {
        std::cout << "You can not learn more than 4 sources" << std::endl;
        return;
    }
    this->source_[num_memorized] = m;
    num_memorized++;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < num_memorized; i++) {
        if (this->source_[i] && this->source_[i]->getType() == type) {
            return this->source_[i]->clone();
        }
    }
    std::cout << "No source for " << type << " is stored" << std::endl;
    return NULL;
}
