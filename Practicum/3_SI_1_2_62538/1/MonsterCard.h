//
// Created by Tegu on 1.5.2021 г..
//

#ifndef INC_1_MONSTERCARD_H
#define INC_1_MONSTERCARD_H
#include "Card.h"

class MonsterCard:virtual public Card{
private:
    unsigned int atk;
    unsigned int def;
public:
    MonsterCard(const string name="", const string effect="", const unsigned int atk=0,const unsigned int def=0);
    MonsterCard(const char* text);

    unsigned int getATK() const;

    unsigned int getDEF() const;

    string getName() const;
    string getEffect() const;

    void setName(const string name);

    void setEffect(const string effect);

    void setATK( const unsigned int atk);

    void setDEF( const unsigned int def);

    string toString() const;
};


#endif //INC_1_MONSTERCARD_H
