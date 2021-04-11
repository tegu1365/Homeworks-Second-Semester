//
// Created by Tegu on 11.4.2021 г..
//

#ifndef INC_1_EQUIPMENT_H
#define INC_1_EQUIPMENT_H

#include "Weapon.h"
#include "Armor.h"
#include <vector>
using namespace std;

template<typename E>
class Equipment {
private:
    vector<E> slots;
    const unsigned short maxSlots=24;
    unsigned short fullSlots;
public:
    Equipment();
    bool isFull();
    bool isEmpty();
    void Empty();
    unsigned short numOfFullSlots();
    int addToEquipment(E _sth);
    int removeFromEquipment(E _sth);
};




#endif //INC_1_EQUIPMENT_H
