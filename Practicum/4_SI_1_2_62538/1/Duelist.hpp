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


#ifndef INC_1_DUELIST_HPP
#define INC_1_DUELIST_HPP
#include "Deck.hpp"
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


#endif //INC_1_DUELIST_HPP
