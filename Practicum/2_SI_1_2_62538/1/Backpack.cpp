/**
*	Solution to homework assignment 2
*	Object Oriented Programming Course
*	Faculty of Mathematics and Informatics of Sofia University
*	Summer semester 2020/2021 *
*	@author Teodora Petkova
*	@idnumber 62538
*	@task 1
*	@compiler VC
*/

#include "Backpack.h"

template<>
Backpack<Money>::Backpack() {
    fullSlots = 1;
    maxSlots = 1;
    slots.emplace_back();
}

template<>
Backpack<Materials>::Backpack() {
    fullSlots = 0;
    maxSlots = 16;
}

template<>
bool Backpack<Money>::isFull() {//always false because we have infinity space for money
    return false;
}

template<>
bool Backpack<Money>::isEmpty() {
    if (fullSlots == 0) {
        return true;
    }
    return (slots[0].getBronzeCoins() + slots[0].getSilverCoins() + slots[0].getGoldCoins() == 0);
}

template<typename B>
void Backpack<B>::Empty() {
    slots.clear();
    fullSlots = 0;
}

template<>
unsigned short Backpack<Materials>::numOfFullSlots() {
    return fullSlots;
}


template<typename B>
int Backpack<B>::removeFromBackpack(B _sth) {

}

template<typename B>
int Backpack<B>::addToBackpack(B _sth) {
    return 0;
}

template<>
Backpack<Money> &Backpack<Money>::operator=(const Backpack<Money> &other) {
    if (this != &other) {
        this->fullSlots = other.fullSlots;
        this->maxSlots = other.maxSlots;
        this->slots[0] = other.slots[0];
    }
    return *this;
}

ostream &operator<<(ostream &out, Backpack<Money> &rhs) {
    out<<"Has "<<rhs.slots[0]<<"\n______________________________________\n";
    return out;
}

ostream &operator<<(ostream &out, Backpack<Materials> &rhs) {
    out<<"Has "<<rhs.fullSlots<<"slots with Materials:\n";
    for(int i=0;i<rhs.fullSlots;i++) {
        out << i << "______________________________\n" << rhs.slots[i] << "\n";
    }
    out<<"______________________________________\n";
    return out;
}

template<>
Backpack<Materials> &Backpack<Materials>::operator=(const Backpack<Materials> &other) {
    if (this != &other) {
        this->fullSlots = other.fullSlots;
        this->maxSlots = other.maxSlots;
        this->slots = other.slots;
    }
    return *this;
}

template<>
unsigned short Backpack<Money>::numOfFullSlots() {
    return fullSlots;
}

template<>
int Backpack<Money>::addToBackpack(Money _sth) {
    if (fullSlots == 0) {
        slots.push_back(_sth);
        return 0;
    }
    slots[0].addBronze(_sth.getBronzeCoins());
    slots[0].addSilver(_sth.getSilverCoins());
    slots[0].addGold(_sth.getGoldCoins());
    return 1;
}

template<>
int Backpack<Materials>::addToBackpack(Materials _sth) {
    if (fullSlots != maxSlots) {
        unsigned short quantityPerSlot = _sth.getQuantityPerSlot();
        if (fullSlots != 0) {
            for (int i = 0; i < fullSlots; i++) {
                if (slots[i].getType() == _sth.getType()) {
                    if (slots[i].getQuantity() != slots[i].getQuantityPerSlot()) {
                        unsigned int newQuantity = slots[i].getQuantity() + _sth.getQuantity();
                        if (newQuantity - quantityPerSlot > 0) {
                            unsigned short addToOldSlot = quantityPerSlot - slots[i].getQuantity();
                            slots[i].addMaterial(addToOldSlot);
                            //____________________________
                            unsigned int forNewSlot = newQuantity - quantityPerSlot;
                            if (forNewSlot < quantityPerSlot) {
                                slots.push_back(Materials(_sth.getType(), forNewSlot));
                                fullSlots++;
                                return 1;
                            } else {
                                int j = forNewSlot / quantityPerSlot;
                                while (j > 0 || fullSlots != maxSlots) {
                                    unsigned short add = forNewSlot - j * quantityPerSlot;
                                    slots.push_back(Materials(_sth.getType(), add));
                                    fullSlots++;
                                    forNewSlot -= add;
                                    j--;
                                }
                                if (fullSlots != maxSlots) {
                                    slots.push_back(Materials(_sth.getType(), forNewSlot));
                                    fullSlots++;
                                }
                                return 2;
                            }
                        } else {
                            slots[i].addMaterial(newQuantity - slots[i].getQuantity());
                            return 3;
                        }
                    }
                }
            }
        }

        unsigned int newQ = _sth.getQuantity();
        int j = newQ / quantityPerSlot;

        while (j > 0 && fullSlots != maxSlots) {
            unsigned short add = newQ - j * quantityPerSlot;
            slots.push_back(Materials(_sth.getType(), add));
            fullSlots++;
            newQ -= add;
            j--;
        }

        if (fullSlots != maxSlots) {
            slots.push_back(Materials(_sth.getType(), newQ));
            fullSlots++;
        }

        return 4;
    }
    return 0;
}

template<>
int Backpack<Money>::removeFromBackpack(Money _sth) {
    if (fullSlots != 0) {
        unsigned int moneyToRemove = _sth.getGoldCoins() * 10000 + _sth.getSilverCoins() * 100 + _sth.getBronzeCoins();
        slots[0].removeMoney(moneyToRemove);
        return 1;
    }
    return 0;
}

template<>
int Backpack<Materials>::removeFromBackpack(Materials _sth) {
    if (fullSlots != 0) {
        unsigned int quantityToRemove = _sth.getQuantity();
        vector<Materials> materialsWithType;
        unsigned int currentQuantity = 0;
        for (int i = 0; i < fullSlots; i++) {
            if (slots[i].getType() == _sth.getType()) {
                materialsWithType.push_back(slots[i]);
                currentQuantity += slots[i].getQuantity();
                slots.erase(slots.begin() + i);
                fullSlots--;
                i = 0;
            }
        }

        if (currentQuantity < quantityToRemove) {
            return 1;
        }
        if (currentQuantity == quantityToRemove) {
            return 2;
        }
        if (quantityToRemove < currentQuantity) {
            currentQuantity -= quantityToRemove;
            Materials toAddBack = Materials(_sth.getType(), currentQuantity);
            addToBackpack(toAddBack);
            return 3;
        }


    }

    return 0;
}

template<>
bool Backpack<Materials>::isEmpty() {
    return fullSlots == 0;
}

template<>
bool Backpack<Materials>::isFull() {//if all slots are on full capacity
    if (fullSlots == maxSlots) {
        for (int i = 0; i < maxSlots; i++) {
            if (slots[i].getQuantity() != slots[i].getQuantityPerSlot()) {
                return false;
            }
        }
        return true;
    }
    return false;
}




