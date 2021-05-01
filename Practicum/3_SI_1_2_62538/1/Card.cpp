/**
*	Solution to homework assignment 3
*	Object Oriented Programming Course
*	Faculty of Mathematics and Informatics of Sofia University
*	Summer semester 2020/2021
*
*	@author Teodora Dimitrova Petkova
*	@idnumber 62538
*	@task 1
*	@compiler VC
*/

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
