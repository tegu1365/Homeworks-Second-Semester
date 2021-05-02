//
// Created by Tegu on 2.5.2021 г..
//

#ifndef INC_1_DUELIST_H
#define INC_1_DUELIST_H
#include "Deck.h"
#include <iostream>
using namespace std;
class Duelist {
private:
    string name;
    Deck deck;
public:
    Duelist(const string name="",const Deck deck=Deck());
    Deck getDeck() const;
    string getName()const;
    void setDeck(const Deck deck);
    void setName(const string name);
    bool saveDeck(const char* filename);
    bool loadDeck(const char* filename);
    void display()const;
};


#endif //INC_1_DUELIST_H
