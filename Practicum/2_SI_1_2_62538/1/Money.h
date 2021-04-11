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

    Money& operator=(const Money& other);

    friend ostream& operator<<(ostream& out,  Money& rhs);
};


#endif //INC_1_MONEY_H
