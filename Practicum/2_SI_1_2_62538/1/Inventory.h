//
// Created by Tegu on 11.4.2021 г..
//

#ifndef INC_1_INVENTORY_H
#define INC_1_INVENTORY_H

#include "Backpack.h"
#include "Equipment.h"
#include<iostream>
using namespace std;

template<class I>
class Inventory {
private:
    I inventory;
public:
    Inventory();
    //Inventory(const I& _inv);
    friend ostream& operator<<(ostream& out, Inventory<I>& rhs);
    friend bool operator==( Inventory<I>& lhs,  Inventory<I>& rhs);
    friend bool operator!=( Inventory<I>& lhs,  Inventory<I>& rhs);

};




#endif //INC_1_INVENTORY_H
