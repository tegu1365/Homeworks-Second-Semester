//
// Created by Tegu on 11.4.2021 г..
//

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

/*
template<>
Inventory<Equipment<Weapon>>::Inventory(const Equipment<Weapon>& _inv) {
    inventory=_inv;
}
template<>
Inventory<Equipment<Armor>>::Inventory(const Equipment<Armor>& _inv) {
    inventory=_inv;
}
template<>
Inventory<Backpack<Money>>::Inventory(const Backpack<Money>& _inv) {
    inventory=Backpack<Money>();
    inventory=_inv;
}
template<>
Inventory<Backpack<Materials>>::Inventory(const Backpack<Materials>& _inv) {
    inventory=_inv;
}*/

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
