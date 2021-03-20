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

#ifndef INC_2_YUGIOH_DUELIST_H
#define INC_2_YUGIOH_DUELIST_H
#include "Deck.h"
using namespace std;
class Duelist {
private:
    char* name;
    Deck deck;
public:
    Duelist();
    Duelist(const char* _name);
//    Duelist(const Duelist& _pl);
//    Duelist& operator=(const Duelist& _pl);
    void setName(char* _name);
    char* getName();
    unsigned int getMagicCardCountInDeck();
    unsigned int getMonsterCardCountInDeck();
    void addMagicCardInDeck(MagicCard _magicCard);
    void addMonsterCardInDeck(MonsterCard _monsterCard);
    void addMagicCardInDeck(char _name[], char _effect[], Type _type);
    void addMonsterCardInDeck(char _name[], unsigned int _ATK, unsigned int _DEF);
    void changeMonsterCardInDeck(unsigned int index, MonsterCard _monsterCard);
    void changeMagicCardInDeck(unsigned int index, MagicCard _magicCard);
    void changeMagicCardInDeck(unsigned int index, char _name[], char _effect[], Type _type);
    void changeMonsterCardInDeck(unsigned int index, char _name[], unsigned int _ATK, unsigned int _DEF);
    void print() const;
  //  ~Duelist();
};


#endif //INC_2_YUGIOH_DUELIST_H
