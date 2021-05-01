//
// Created by Tegu on 1.5.2021 г..
//

#ifndef INC_1_PENDULUMCARD_H
#define INC_1_PENDULUMCARD_H
#include "MagicCard.h"
#include "MonsterCard.h"

class PendulumCard:virtual public MagicCard,virtual public MonsterCard{
private:
    unsigned short scale;
public:
    PendulumCard(const string name="",const string effect="",const unsigned int atk=0,const unsigned int def=0, const Type type=NT, const unsigned short scale=1);
    PendulumCard(const char* text);
    unsigned short getScale()const;
    void setScale(const unsigned short scale);
    string toString()const;
};


#endif //INC_1_PENDULUMCARD_H
