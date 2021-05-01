//
// Created by Tegu on 1.5.2021 г..
//

#include "Card.h"

Card::Card(const string name, const string effect) {
    this->name=name;
    this->effect=effect;
}

string Card::getName() const {
    return name;
}

string Card::getEffect() const {
    return effect;
}

void Card::setName(const string name) {
    this->name=name;
}

void Card::setEffect(const string effect) {
    this->effect=effect;
}

string Card::toString() const {
    string result=name+"|"+effect;
    return result;
}
