//
// Created by Tegu on 10.4.2021 г..
//

#ifndef INC_1_MONEY_H
#define INC_1_MONEY_H

#include <iostream>
using namespace std;

class Money {
private:
    unsigned int numOfMoney;//number of bronze coins
public:
    Money();
    Money(unsigned int coins);
    unsigned int getGoldCoins();
    unsigned int getSilverCoins();
    unsigned int getBronzeCoins();
    void addMoney(unsigned int coins);
    void addSilver(unsigned int coins);
    void addGold(unsigned int coins);
    void addBronze(unsigned int coins);
    void removeMoney(unsigned int coins);
    void print();
};


#endif //INC_1_MONEY_H
