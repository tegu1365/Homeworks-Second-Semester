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
    this->monsterCards.clear();
    this->magicCards.clear();
    this->pendulumCards.clear();
}

Deck &Deck::operator=(const Deck &sth) {
    if(this != &sth){
      this->name=sth.name;
      this->magicCards=sth.magicCards;
      this->monsterCards=sth.monsterCards;
      this->pendulumCards=sth.pendulumCards;
    }
    return *this;
}

Deck::Deck(const Deck &deck) {
    this->name=deck.name;
    this->magicCards=deck.magicCards;
    this->monsterCards=deck.monsterCards;
    this->pendulumCards=deck.pendulumCards;
}

string Deck::toString() const {
    string result =
            this->name + "|" + to_string(this->getNumberOfMonsterCards()) + "|" + to_string(this->getNumberOfMagicCards()) +
            "|" + to_string(this->getNumberOfPendulumCards())+"\n";
    for(int i=0;i<monsterCards.size();i++){
        result.append(monsterCards[i].toString()+"\n");
    }
    for(int i=0;i<magicCards.size();i++){
        result.append(magicCards[i].toString()+"\n");
    }
    for(int i=0;i<pendulumCards.size();i++){
        result.append(pendulumCards[i].toString()+"\n");
    }
    return result;
}

Deck::Deck(const char *text) {
    string str = text;
    vector<string> list;

    string current = "";
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '\n') {
            list.push_back(current);
            current = "";
        } else {
            char a = str[i];
            current.push_back(a);
        }
    }
    list.push_back(current);
    current="";
    vector<string> line;

    for (int i = 0; i < list[0].size(); i++) {
        if (str[i] == '|') {
            line.push_back(current);
            current = "";
        } else {
            char a = str[i];
            current.push_back(a);
        }
    }
    line.push_back(current);
    this->name=line[0];
    int numOfMonst=stoi(line[1]);
    int numOfMagic=stoi(line[2]);
    int numOfPend=stoi(line[3]);
    line.clear();
    current="";
    //cout<<numOfMonst<<"-"<<numOfMagic<<"-"<<numOfPend<<endl;
    int indexOfLine=1;
    for(int i=0;i<numOfMonst;i++){
        MonsterCard m=MonsterCard(list[indexOfLine].c_str());
        monsterCards.push_back(m);
        //cout<<indexOfLine<<". "<<m.getName()<<endl;
        indexOfLine++;
    }
    for(int i=0;i<numOfMagic;i++){
        MagicCard m=MagicCard(list[indexOfLine].c_str());
        magicCards.push_back(m);
      //  cout<<indexOfLine<<". "<<m.toString()<<endl;
        indexOfLine++;
    }
    for(int i=0;i<numOfPend;i++){
        PendulumCard m=PendulumCard(list[indexOfLine].c_str());
        pendulumCards.push_back(m);
       // cout<<indexOfLine<<". "<<m.toString()<<endl;
        indexOfLine++;
    }
}
