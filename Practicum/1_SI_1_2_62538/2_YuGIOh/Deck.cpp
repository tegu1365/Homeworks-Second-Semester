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

#include "Deck.h"
bool equal(char a[],char b[]){
    for(int i=0;a[i]!='\0';i++){
        if(a[i]!=b[i])
            return 0;
    }
    return 1;
}

Deck::Deck() {
    this->setMagicCardCount(0);
    this->setMonsterCardCount(0);
    monsterCards=new MonsterCard[20];
    magicCards=new MagicCard[20];
}

Deck::Deck(MagicCard *_magicCard, MonsterCard *_monsterCard) {
    for(int i=0;i<20;i++){
        magicCards[i]=_magicCard[i];
        monsterCards[i]=_monsterCard[i];
    }
}

Deck::Deck(MagicCard _magicCard, MonsterCard _monsterCard) {
    this->setMagicCardCount(0);
    this->setMonsterCardCount(0);
    monsterCards=new MonsterCard[20];
    magicCards=new MagicCard[20];
    this->addMagicCard(_magicCard);
    this->addMonsterCard(_monsterCard);
}

void Deck::setMagicCardCount(unsigned int _count) {
    magicCardCount=_count;
}

void Deck::setMonsterCardCount(unsigned int _count) {
    monsterCardCount=_count;
}

unsigned int Deck::getMonsterCardCount() {
    return monsterCardCount;
}

unsigned int Deck::getMagicCardCount() {
    return magicCardCount;
}

void Deck::addMagicCard(MagicCard _magicCard) {
    for(int i=0;i<20;i++){
        if(equal(magicCards[i].getName(),"NULL")){
            magicCards[i]=_magicCard;
            break;
        }
        if(i==19){
            magicCards[i]=_magicCard;
        }
    }
    this->setMagicCardCount(this->getMagicCardCount()+1);
}

void Deck::addMonsterCard(MonsterCard _monsterCard) {
    for(int i=0;i<20;i++){
        if(equal(monsterCards[i].getName(),"NULL")){
            monsterCards[i]=_monsterCard;
            break;
        }
        if(i==19){
            monsterCards[i]=_monsterCard;
        }
    }
    this->setMonsterCardCount(this->getMonsterCardCount()+1);
}

void Deck::addMagicCard(char *_name, char *_effect, Type _type) {
    MagicCard newMagicCard=MagicCard(_name,_effect,_type);
    addMagicCard(newMagicCard);
    //cout<<"Magic added\n";
}

void Deck::addMonsterCard(char *_name, unsigned int _ATK, unsigned int _DEF) {
    MonsterCard newMonsterCard=MonsterCard(_name,_ATK,_DEF);
    addMonsterCard(newMonsterCard);
    //cout<<"Monster added\n";
}

void Deck::changeMonsterCard(unsigned int index, MonsterCard _monsterCard) {
    if(index>=0 && index<20) {
        if(equal(monsterCards[index].getName(),"NULL")){
            this->setMonsterCardCount(this->getMonsterCardCount()+1);
        }
        monsterCards[index] = _monsterCard;
    }
}

void Deck::changeMagicCard(unsigned int index, MagicCard _magicCard) {
    if(index>=0 && index<20) {
        if(equal(magicCards[index].getName(),"NULL")){
            this->setMagicCardCount(this->getMagicCardCount()+1);
        }
        magicCards[index]=_magicCard;
    }
}

void Deck::changeMagicCard(unsigned int index, char *_name, char *_effect, Type _type) {
    MagicCard newMagicCard=MagicCard(_name,_effect,_type);
    changeMagicCard(index,newMagicCard);
}

void Deck::changeMonsterCard(unsigned int index, char *_name, unsigned int _ATK, unsigned int _DEF) {
    MonsterCard newMonsterCard=MonsterCard(_name,_ATK,_DEF);
    changeMonsterCard(index,newMonsterCard);
}



void Deck::print() const {
    cout<<"MAGIC CARDS: \n";
    for(int i=0;i<20;i++){
        if(!equal(magicCards[i].getName(),"NULL")) {
            magicCards[i].print();
        }
    }
    cout<<"MONSTER CARDS: \n";
    for(int i=0;i<20;i++){
        if(!equal(monsterCards[i].getName(),"NULL")){
            monsterCards[i].print();
        }
    }
}

//Deck::~Deck() {
//    delete[] magicCards;
//    delete[] monsterCards;
//}
