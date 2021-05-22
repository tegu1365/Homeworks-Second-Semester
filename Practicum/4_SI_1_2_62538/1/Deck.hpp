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

#ifndef INC_1_DECK_HPP
#define INC_1_DECK_HPP

#include "Card.hpp"
#include "MagicCard.hpp"
#include "MonsterCard.hpp"
#include "PendulumCard.hpp"
#include <vector>

class Deck {
private:
    string name;
    vector<Card *> cards;
    unsigned int numOfMonsters, numOfMagic, numOfPendulum, numOfCards;
public:
    Deck(const string name = "");

    Deck(const Deck &deck);

    Deck(const char *text);

    unsigned int getNumberOfMagicCards() const;

    unsigned int getNumberOfMonsterCards() const;

    unsigned int getNumberOfPendulumCards() const;

    unsigned int getNumberOfCards() const;

    void addCard(Card *card);

    void setCard(const unsigned int index, Card *card);

    void shuffle();

    void clear();

    Deck &operator=(const Deck &sth);

    string toString() const;

    Card* operator[](unsigned int index)const;

    ~Deck();
};


#endif //INC_1_DECK_HPP
