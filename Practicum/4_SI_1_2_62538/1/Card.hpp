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

#ifndef INC_1_CARD_H
#define INC_1_CARD_H

#include <iostream>
#include <string>

using namespace std;

enum Type {
    trap, buff, spell, NT
};

enum CardType{
    MAGIC,
    MONSTER,
    PENDULUM,
    NoType
};

class Card {
protected:
    CardType type;
    string name;
    string effect;
    unsigned int rarity;
public:
    Card(const CardType type=NoType,const string name = "", const string effect = "", const unsigned int rarity=0);

    string getName() const;
    string getEffect() const;
    unsigned int getRarity() const;
    CardType getCardType() const;

    void setName(const string name);
    void setEffect(const string effect);
    void setRarity(const unsigned int rarity);
    void setCardType(const CardType type);

    virtual string toString() const;

    friend bool operator>(const Card& lhs, const Card& rhs);
    friend bool operator<(const Card& lhs, const Card& rhs);

    virtual Card* clone()=0;
    virtual ~Card()=default;
};


#endif //INC_1_CARD_H
