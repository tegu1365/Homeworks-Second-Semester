//
// Created by Tegu on 1.5.2021 г..
//

#ifndef INC_1_MAGICCARD_H
#define INC_1_MAGICCARD_H
#include "Card.h"

class MagicCard:virtual public Card{
private:
    Type type;
public:
    MagicCard(const string name="",const string effect="", const Type type=NT);
    MagicCard(const char* text);

    Type getType() const;

    void setType(const Type type);

    string toString()const;
};


#endif //INC_1_MAGICCARD_H
