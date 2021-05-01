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

#include "Deck.h"

Deck::Deck(const string name) {
    this->name=name;
}

unsigned int Deck::getNumberOfMagicCards() const {
    return magicCards.size();
}

unsigned int Deck::getNumberOfMonsterCards() const {
    return monsterCards.size();
}

unsigned int Deck::getNumberOfPendulumCards() const {
    return pendulumCards.size();
}

void Deck::addMagicCard(const MagicCard card) {
    magicCards.push_back(card);
}

void Deck::addMonsterCard(const MonsterCard card) {
    monsterCards.push_back(card);
}

void Deck::addPendulumCard(const PendulumCard card) {
    pendulumCards.push_back(card);
}

void Deck::changeMagicCard(const MagicCard card, const unsigned int index) {
    if(index<magicCards.size()){
        magicCards[index].setName(card.getName());
        magicCards[index].setEffect(card.getEffect());
        magicCards[index].setType(card.getType());
    }else{
        magicCards.push_back(card);
    }
}

void Deck::changeMonsterCard(const MonsterCard card, const unsigned int index) {
    if(index<monsterCards.size()){
        monsterCards[index].setName(card.getName());
        monsterCards[index].setEffect(card.getEffect());
        monsterCards[index].setATK(card.getATK());
        monsterCards[index].setDEF(card.getDEF());
    }else{
        monsterCards.push_back(card);
    }
}

void Deck::changePendulumCard(const PendulumCard card, const unsigned int index) {
    if(index<pendulumCards.size()){
        pendulumCards[index].setName(card.getName());
        pendulumCards[index].setEffect(card.getEffect());
        pendulumCards[index].setATK(card.getATK());
        pendulumCards[index].setDEF(card.getDEF());
        pendulumCards[index].setType(card.getType());
        pendulumCards[index].setScale(card.getScale());
    }else{
        pendulumCards.push_back(card);
    }
}

void Deck::clear() {
    monsterCards.clear();
    magicCards.clear();
    pendulumCards.clear();
}
