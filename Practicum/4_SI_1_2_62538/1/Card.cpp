/**
*	Solution to homework assignment 4
*	Object Oriented Programming Course
*	Faculty of Mathematics and Informatics of Sofia University
*	Summer semester 2020/2021
*
*	@author Teodora Dimitrova Petkova
*	@idnumber 62538
*	@task 1
*	@compiler VC
*/

#include "Card.hpp"

Card::Card(const CardType type,const string name, const string effect, const unsigned int rarity) {
    this->type=type;
    this->name = name;
    this->effect = effect;
    this->rarity=rarity;
}

string Card::getName() const {
    return name;
}

string Card::getEffect() const {
    return effect;
}

void Card::setName(const string name) {
    this->name = name;
}

void Card::setEffect(const string effect) {
    this->effect = effect;
}

string Card::toString() const {
    string result = name + "|" + effect+"|"+to_string(rarity);
    return result;
}

unsigned int Card::getRarity() const {
    return rarity;
}

void Card::setRarity(const unsigned int rarity) {
    this->rarity=rarity;
}

bool operator>(const Card &lhs, const Card &rhs) {
    return lhs.rarity>rhs.rarity;
}

bool operator<(const Card &lhs, const Card &rhs) {
    return lhs.rarity<rhs.rarity;
}

CardType Card::getCardType() const {
    return type;
}

void Card::setCardType(const CardType type) {
    this->type=type;
}
