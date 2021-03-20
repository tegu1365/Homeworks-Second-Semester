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
#include "MonsterCard.h"
MonsterCard::MonsterCard() {
    this->setName("NULL");
    this->setATK(0);
    this->setDEF(0);
}

MonsterCard::MonsterCard(char *_name, unsigned int _ATK, unsigned int _DEF) {
    this->setName(_name);
    this->setATK(_ATK);
    this->setDEF(_DEF);
}

unsigned int MonsterCard::getATK() const{
    return atk;
}

unsigned int MonsterCard::getDEF() const{
    return def;
}

char * MonsterCard::getName(){
    return name;
}

void MonsterCard::setName(char *_name) {
    int i = 0;
    while (_name[i] != '\0' && i < 26) {
        name[i] = _name[i];
        i++;
    }
    name[i]='\0';

}

void MonsterCard::setATK(unsigned int _ATK) {
    atk = _ATK;
}

void MonsterCard::setDEF(unsigned int _DEF) {
    def = _DEF;
}

void MonsterCard::print() const {
    cout << name << "\n ATK: " << atk << "; DEF: " << def << endl;
}


