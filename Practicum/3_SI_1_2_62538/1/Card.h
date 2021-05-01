//
// Created by Tegu on 1.5.2021 г..
//

#ifndef INC_1_CARD_H
#define INC_1_CARD_H
#include <iostream>
#include <string>
using namespace std;

class Card {
protected:
    string name;
    string effect;
public:
    Card(const string name="",const string effect="");
    string getName() const;
    string getEffect()const;
    void setName(const string name);
    void setEffect(const string effect);
    string toString()const;
};


#endif //INC_1_CARD_H
