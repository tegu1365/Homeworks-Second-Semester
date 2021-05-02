//
// Created by Tegu on 2.5.2021 г..
//

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
    return true;
}

void Duelist::display() const {
    cout<<name<<endl;
    cout<<deck.toString()<<endl;
}

