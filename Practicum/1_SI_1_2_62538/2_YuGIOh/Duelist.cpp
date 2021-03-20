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

#include "Duelist.h"

Duelist::Duelist() {
    this->name = "NUll\0";
    deck = Deck();
}

Duelist::Duelist(const char* _name) {
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);
    this->name[strlen(_name) + 1]='\0';
    deck = Deck();
}

void Duelist::setName(char *_name) {
    delete[] name;
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);
}

char * Duelist::getName() {
    return name;
}

unsigned int Duelist::getMagicCardCountInDeck() {
    return deck.getMagicCardCount();
}

unsigned int Duelist::getMonsterCardCountInDeck() {
    return deck.getMonsterCardCount();
}

void Duelist::addMagicCardInDeck(MagicCard _magicCard) {
    deck.addMagicCard(_magicCard);
}

void Duelist::addMonsterCardInDeck(MonsterCard _monsterCard) {
    deck.addMonsterCard(_monsterCard);
}

void Duelist::addMagicCardInDeck(char *_name, char *_effect, Type _type) {
    deck.addMagicCard(_name, _effect, _type);
}

void Duelist::addMonsterCardInDeck(char *_name, unsigned int _ATK, unsigned int _DEF) {
    deck.addMonsterCard(_name, _ATK, _DEF);
}

void Duelist::changeMonsterCardInDeck(unsigned int index, MonsterCard _monsterCard) {
    deck.changeMonsterCard(index, _monsterCard);
}

void Duelist::changeMagicCardInDeck(unsigned int index, MagicCard _magicCard) {
    deck.changeMagicCard(index, _magicCard);
}

void Duelist::changeMagicCardInDeck(unsigned int index, char *_name, char *_effect, Type _type) {
    deck.changeMagicCard(index, _name, _effect, _type);
}

void Duelist::changeMonsterCardInDeck(unsigned int index, char *_name, unsigned int _ATK, unsigned int _DEF) {
    deck.changeMonsterCard(index, _name, _ATK, _DEF);
}

void Duelist::print() const {
    cout<<name<<endl;
    deck.print();
}

//Duelist::~Duelist() {
//    delete[] name;
//}

//Duelist::Duelist(const Duelist &_pl) {
//    this->name = new char[strlen(_pl.name) + 1];
//    strcpy(this->name, _pl.name);
//    this->deck = _pl.deck;
//}
//
//Duelist &Duelist::operator=(const Duelist &_pl) {
//    if(this != &_pl) {
//        delete[] name;
//
//        this->name = new char[strlen(_pl.name) + 1];
//        strcpy(this->name, _pl.name);
//        this->deck = _pl.deck;
//    }
//
//    return *this;
//}





