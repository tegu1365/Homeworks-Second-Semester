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

#include "Inventory.h"
template<>
Inventory<Equipment<Weapon>>::Inventory() {
    inventory=Equipment<Weapon>();
}

template<>
Inventory<Equipment<Armor>>::Inventory() {
    inventory=Equipment<Armor>();
}
template<>
Inventory<Backpack<Money>>::Inventory() {
    inventory=Backpack<Money>();
}
template<>
Inventory<Backpack<Materials>>::Inventory() {
    inventory=Backpack<Materials>();
}

template<>
Inventory<Equipment<Weapon>>::Inventory( Equipment<Weapon>& _inv) {
    inventory=_inv;
}
template<>
Inventory<Equipment<Armor>>::Inventory( Equipment<Armor>& _inv) {
    inventory=_inv;
}
template<>
Inventory<Backpack<Money>>::Inventory( Backpack<Money>& _inv) {
    inventory=Backpack<Money>();
    inventory=_inv;
}
template<>
Inventory<Backpack<Materials>>::Inventory( Backpack<Materials>& _inv) {
    inventory=_inv;
}

ostream &operator<<(ostream &out,Inventory<Backpack<Money>> &rhs) {
    out<<rhs.inventory;
    return out;
}

ostream &operator<<(ostream &out,Inventory<Backpack<Materials>> &rhs) {
    out<<rhs.inventory;
    return out;
}

ostream &operator<<(ostream &out,Inventory<Equipment<Armor>> &rhs) {
    out<<rhs.inventory;
    return out;
}
ostream &operator<<(ostream &out,Inventory<Equipment<Weapon>> &rhs) {
    out<<rhs.inventory;
    return out;
}


bool operator==( Inventory<Backpack<Money>> &lhs,  Inventory<Backpack<Money>> &rhs) {
    return true;//money has zero slots
}

bool operator==( Inventory<Backpack<Materials>> &lhs,  Inventory<Backpack<Materials>> &rhs) {
    return (lhs.inventory.numOfFullSlots()==rhs.inventory.numOfFullSlots());
}

bool operator==( Inventory<Equipment<Armor>> &lhs,  Inventory<Equipment<Armor>> &rhs) {
    return (lhs.inventory.numOfFullSlots()==rhs.inventory.numOfFullSlots());
}

bool operator==( Inventory<Equipment<Weapon>> &lhs,  Inventory<Equipment<Weapon>> &rhs) {
    return (lhs.inventory.numOfFullSlots()==rhs.inventory.numOfFullSlots());
}

bool operator!=( Inventory<Backpack<Money>> &lhs,  Inventory<Backpack<Money>> &rhs) {
    return false;
}

template<class I>
I Inventory<I>::getInventory() {
    return inventory;
}
template<>
Backpack<Money> Inventory<Backpack<Money>>::getInventory() {
    return inventory;
}
template<>
Backpack<Materials> Inventory<Backpack<Materials>>::getInventory() {
    return inventory;
}
template<>
Equipment<Weapon> Inventory<Equipment<Weapon>>::getInventory() {
    return inventory;
}
template<>
Equipment<Armor> Inventory<Equipment<Armor>>::getInventory() {
    return inventory;
}

bool operator!=( Inventory<Backpack<Materials>> &lhs,  Inventory<Backpack<Materials>> &rhs) {
    return !(lhs==rhs);
}
bool operator!=( Inventory<Equipment<Armor>> &lhs,  Inventory<Equipment<Armor>> &rhs) {
    return !(lhs==rhs);
}
bool operator!=( Inventory<Equipment<Weapon>> &lhs,  Inventory<Equipment<Weapon>> &rhs) {
    return !(lhs==rhs);
}
template<typename I>
bool operator==( Inventory<I>& lhs,  Inventory<I>& rhs){
    return (lhs.inventory.numOfFullSlots()==rhs.inventory.numOfFullSlots());
}
template<typename I>
bool operator!=( Inventory<I>& lhs,  Inventory<I>& rhs){
    return !(lhs==rhs);
}
