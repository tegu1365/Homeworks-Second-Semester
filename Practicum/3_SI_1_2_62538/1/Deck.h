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

#ifndef INC_1_DECK_H
#define INC_1_DECK_H

#include "Card.h"
#include "MagicCard.h"
#include "MonsterCard.h"
#include "PendulumCard.h"
#include <vector>

class Deck {
private:
    string name;
    vector<MagicCard> magicCards;
    vector<MonsterCard> monsterCards;
    vector<PendulumCard> pendulumCards;
public:
    Deck(const string name="");
    Deck(const Deck& deck);
    Deck(const char* text);
    unsigned int getNumberOfMagicCards()const;
    unsigned int getNumberOfMonsterCards()const;
    unsigned int getNumberOfPendulumCards()const;
    void addMagicCard(const MagicCard card);
    void addMonsterCard(const MonsterCard card);
    void addPendulumCard(const PendulumCard card);
    void changeMagicCard(const MagicCard card, const unsigned int index);
    void changeMonsterCard(const MonsterCard card,const unsigned int index);
    void changePendulumCard(const PendulumCard card,const unsigned int index);
    void clear();
    Deck& operator=(const Deck& sth);
    string toString()const;
};


#endif //INC_1_DECK_H
