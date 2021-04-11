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
