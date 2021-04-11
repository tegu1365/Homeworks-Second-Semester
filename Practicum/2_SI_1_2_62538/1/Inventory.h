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
