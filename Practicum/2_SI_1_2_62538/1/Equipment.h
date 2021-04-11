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
    unsigned short maxSlots=24;
    unsigned short fullSlots;
    vector<E> slots;

    //bool isEven(int k, E _sth);
public:
    Equipment();
    bool isEquipmentFull();
    bool isEquipmentEmpty();
    void Empty();
    unsigned short numOfFullSlots();
    int addToEquipment(E _sth);
    int removeFromEquipment(E _sth);
    E theBestEquipment();
    friend bool operator!=(const Equipment<E>& lhs, const Equipment<E>& rhs );
    friend bool operator==(const Equipment<E>& lhs, const Equipment<E>& rhs );
    Equipment<E>& operator=(const Equipment<E>& other);
    friend ostream& operator<<(ostream& out,  Equipment<E>& rhs);
};




#endif //INC_1_EQUIPMENT_H
