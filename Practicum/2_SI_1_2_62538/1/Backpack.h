//
// Created by Tegu on 10.4.2021 г..
//

#ifndef INC_1_BACKPACK_H
#define INC_1_BACKPACK_H

#include <iostream>
#include <vector>
#include "Materials.h"
#include "Money.h"
using namespace std;

template <typename B>
class Backpack {
private:
    unsigned short maxSlots;
    unsigned short fullSlots;
    vector<B> slots;
public:
    Backpack();
    bool isFull();
    bool isEmpty();
    void Empty();
    unsigned short numOfFullSlots();
    int addToBackpack(B _sth);
    int removeFromBackpack(B _sth);
};




#endif //INC_1_BACKPACK_H
