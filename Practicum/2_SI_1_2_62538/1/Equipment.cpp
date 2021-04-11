//
// Created by Tegu on 11.4.2021 г..
//

#include "Equipment.h"

template<typename E>
Equipment<E>::Equipment() {
    fullSlots = 0;
}

template<>
Equipment<Armor>::Equipment() {
    fullSlots = 0;
}

template<>
Equipment<Weapon>::Equipment() {
    fullSlots = 0;
}


template<typename E>
bool Equipment<E>::isEquipmentFull() {
    return fullSlots == maxSlots;
}

template<>
bool Equipment<Weapon>::isEquipmentFull() {
    return fullSlots == maxSlots;
}

template<>
bool Equipment<Armor>::isEquipmentFull() {
    return fullSlots == maxSlots;
}

template<typename E>
bool Equipment<E>::isEquipmentEmpty() {
    return fullSlots == 0;
}

template<>
bool Equipment<Weapon>::isEquipmentEmpty() {
    return fullSlots == 0;
}

template<>
bool Equipment<Armor>::isEquipmentEmpty() {
    return fullSlots == 0;
}

template<typename E>
void Equipment<E>::Empty() {
    slots.clear();
    fullSlots = 0;
}

template<typename E>
unsigned short Equipment<E>::numOfFullSlots() {
    return fullSlots;
}

template<>
unsigned short Equipment<Weapon>::numOfFullSlots() {
    return fullSlots;
}

template<>
unsigned short Equipment<Armor>::numOfFullSlots() {
    return fullSlots;
}

template<typename E>
int Equipment<E>::addToEquipment(E _sth) {
    if (fullSlots != maxSlots) {
        slots.push_back(_sth);
        fullSlots++;
        return 1;
    }
    return 0;
}

template<>
int Equipment<Weapon>::addToEquipment(Weapon _sth) {
    if (_sth.getSlots() != 0) {
        if (fullSlots != maxSlots) {
            if (_sth.getSlots() == 2) {
                slots.push_back(_sth);
                slots.push_back(_sth);
                fullSlots += 2;
                return 2;
            } else {
                slots.push_back(_sth);
                fullSlots++;
                return 1;
            }
        }
    }
    return 0;
}

template<>
int Equipment<Armor>::addToEquipment(Armor _sth) {
    if (_sth == Armor()) {
        return 0;
    }
    if (fullSlots != maxSlots) {
        slots.push_back(_sth);
        fullSlots++;
        return 1;
    }

    return -1;
}

template<typename E>
int Equipment<E>::removeFromEquipment(E _sth) {
    for (int i = 0; i < fullSlots; i++) {
        if (slots[i].getName() == _sth.getName()) {
            slots.erase(slots.begin() + i);
            fullSlots--;
            i = 0;
        }
    }
    return 0;
}

template<>
Weapon Equipment<Weapon>::theBestEquipment() {
    Weapon bestWeapon = Weapon();
    if (fullSlots != 0) {
        if (fullSlots == 1) {
            return slots[0];
        }
        for (int i = 0; i < fullSlots; i++) {
            if (bestWeapon.getWeaponScore() < slots[i].getWeaponScore()) {
                bestWeapon = slots[i];
            }
        }
    }
    return bestWeapon;
}

bool operator==(const Equipment<Weapon> &lhs, const Equipment<Weapon> &rhs) {
    if(lhs.fullSlots==rhs.fullSlots){
        for(int i=0;i<lhs.fullSlots;i++){
            if(lhs.slots[i]!=rhs.slots[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}

bool operator!=(const Equipment<Weapon> &lhs, const Equipment<Weapon> &rhs) {
    return !(lhs==rhs);
}

bool operator==(const Equipment<Armor> &lhs, const Equipment<Armor> &rhs) {
    if(lhs.fullSlots==rhs.fullSlots){
        for(int i=0;i<lhs.fullSlots;i++){
            if(lhs.slots[i]!=rhs.slots[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}

bool operator!=(const Equipment<Armor> &lhs, const Equipment<Armor> &rhs) {
    return !(lhs==rhs);
}

template<>
Armor Equipment<Armor>::theBestEquipment() {
    Armor bestArmor = Armor();
    if (fullSlots != 0) {
        if (fullSlots == 1) {
            return slots[0];
        }
        for (int i = 0; i < fullSlots; i++) {
            if (bestArmor.getGearScore() < slots[i].getGearScore()) {
                bestArmor = slots[i];
            }
        }
    }
    return bestArmor;
}


template<>
int Equipment<Armor>::removeFromEquipment(Armor _sth) {
    for (int i = 0; i < fullSlots; i++) {
        if (slots[i] == _sth) {
            slots.erase(slots.begin() + i);
            fullSlots--;
            i = 0;
        }
    }
    if (fullSlots == 1) {
        if (slots[0] == _sth) {
            slots.clear();
            fullSlots = 0;
        }
    }
    return 0;
}

template<>
int Equipment<Weapon>::removeFromEquipment(Weapon _sth) {
    for (int i = 0; i < fullSlots; i++) {
        if (slots[i] == _sth) {
            slots.erase(slots.begin() + i);
            i = 0;
            fullSlots--;
        }
    }
    if (fullSlots == 1) {
        if (slots[0] == _sth) {
            slots.clear();
            fullSlots = 0;
        }
    }
    return 0;
}



