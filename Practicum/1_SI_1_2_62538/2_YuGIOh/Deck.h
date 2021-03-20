/**
*	Solution to homework assignment 1
*	Object Oriented Programming Course
*	Faculty of Mathematics and Informatics of Sofia University
*	Summer semester 2020/2021
*
*	@author Teodora Dimitrova Petkova
*	@idnumber 62538
*	@task 2
*	@compiler VC
*/

#ifndef INC_2_YUGIOH_DECK_H
#define INC_2_YUGIOH_DECK_H


#include "MagicCard.h"
#include "MonsterCard.h"

using namespace std;

class Deck {
private:
    MagicCard* magicCards;
    MonsterCard* monsterCards;
    unsigned int magicCardCount;
    unsigned int monsterCardCount;
public:
    Deck();
    Deck(MagicCard _magicCard,MonsterCard _monsterCard);
    Deck(MagicCard _magicCard[],MonsterCard _monsterCard[]);
    unsigned int getMagicCardCount();
    unsigned int getMonsterCardCount();
    void setMagicCardCount(unsigned int _count);
    void setMonsterCardCount(unsigned int _count);
    void addMagicCard(MagicCard _magicCard);
    void addMonsterCard(MonsterCard _monsterCard);
    void addMagicCard(char _name[], char _effect[], Type _type);
    void addMonsterCard(char _name[], unsigned int _ATK, unsigned int _DEF);
    void changeMonsterCard(unsigned int index, MonsterCard _monsterCard);
    void changeMagicCard(unsigned int index, MagicCard _magicCard);
    void changeMagicCard(unsigned int index, char _name[], char _effect[], Type _type);
    void changeMonsterCard(unsigned int index, char _name[], unsigned int _ATK, unsigned int _DEF);
    void print()const;
 //   ~Deck();
};



#endif //INC_2_YUGIOH_DECK_H
