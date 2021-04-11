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
    Backpack<B>& operator=(const Backpack<B>& other);
    friend ostream& operator<<(ostream& out,  Backpack<B>& rhs);

};




#endif //INC_1_BACKPACK_H
