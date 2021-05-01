//
// Created by Tegu on 1.5.2021 г..
//

#include "MonsterCard.h"
#include <vector>

int getSize(const char* str){
    int i=0;
    while(str[i]!='\0'){
        i++;
    }
    return i;
}

MonsterCard::MonsterCard(const string name, const string effect, const unsigned int atk, const unsigned int def)
:Card(name,effect) {
    this->atk=atk;
    this->def=def;
}

unsigned int MonsterCard::getATK() const {
    return atk;
}

unsigned int MonsterCard::getDEF() const {
    return def;
}

string MonsterCard::getName() const {
    return Card::getName();
}

string MonsterCard::getEffect() const {
    return Card::getEffect();
}

void MonsterCard::setName(const string name) {
    Card::setName(name);
}

void MonsterCard::setEffect(const string effect) {
    Card::setEffect(effect);
}

void MonsterCard::setATK(const unsigned int atk) {
    this->atk=atk;
}

void MonsterCard::setDEF(const unsigned int def) {
    this->def=def;
}

string MonsterCard::toString() const {
    string result= name+"|"+effect+"|"+to_string(atk)+"|"+to_string(def);
    return result;
}

MonsterCard::MonsterCard(const char* text):Card() {
    string str=text;
    vector<string> list;

    string current="";
    for(int i=0;i<str.size();i++){
        if(str[i]=='|'){
            list.push_back(current);
            current="";
        }else {
           char a=str[i];
           current.push_back(a);
        }
    }
    list.push_back(current);
    Card::setName(list[0]);
    Card::setEffect(list[1]);
    this->atk=stoi(list[2]);
    this->def=stoi(list[3]);
}

