//
// Created by Tegu on 10.4.2021 г..
//

#include "Money.h"
const unsigned int bronzeToSilver=100;
const unsigned int bronzeToGold=10000;

Money::Money() {
    numOfMoney=0;
}

Money::Money(unsigned int coins) {
    numOfMoney=coins;
}

unsigned int Money::getGoldCoins() {
    return numOfMoney/bronzeToGold;
}

unsigned int Money::getSilverCoins() {
    return (numOfMoney/bronzeToSilver)%100;
}

unsigned int Money::getBronzeCoins() {
    return numOfMoney%100;
}

void Money::addMoney(unsigned int coins) {
    numOfMoney+=coins;
}

void Money::addSilver(unsigned int coins) {
    addMoney(coins*bronzeToSilver);
}

void Money::addGold(unsigned int coins) {
    addMoney(coins*bronzeToGold);
}

void Money::addBronze(unsigned int coins) {
    addMoney(coins);
}

void Money::print() {
    cout<<"Money: "<< this->getGoldCoins()<<"g. "<<this->getSilverCoins()<<"s. "<<this->getBronzeCoins()<<"br. \n";
}

