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


#include "Duelist.h"
#include "fstream"

Duelist::Duelist(const string name, const Deck deck) {
    this->name = name;
    this->deck = deck;
}

Deck Duelist::getDeck() const {
    return this->deck;
}

string Duelist::getName() const {
    return name;
}

void Duelist::setDeck(const Deck deck) {
    this->deck = deck;
}

void Duelist::setName(const string name) {
    this->name = name;
}

bool Duelist::saveDeck(const char *filename) {
    fstream file;
    file.open(filename);
    if (!file.is_open()) {
       return false;
    }
    string write=deck.toString();
    file<<write;
    file.close();
    return true;
}

bool Duelist::loadDeck(const char *filename) {
    fstream file;
    file.open(filename);
    if (!file.is_open()) {
        return false;
    }
    string read="";
    string line="";
    while ( getline (file,line) ) {
        read.append(line+"\n");
    }
    this->deck.clear();
    this->deck=Deck(read.c_str());
    file.close();
    return true;
}

void Duelist::display() const {
    cout<<name<<endl;
    cout<<deck.toString()<<endl;
}

