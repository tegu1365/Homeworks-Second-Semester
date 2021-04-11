//
// Created by Tegu on 11.4.2021 г..
//

#include "Armor.h"

Armor::Armor() {
    numOfEffects=0;
    gearScore=0;
    type=Null;
    defense=0;
}

Armor::Armor(ArmorType _type, unsigned int _def) {
    numOfEffects=0;
    gearScore=0;
    type=_type;
    defense=_def;
}

Armor::Armor(ArmorType _type, unsigned int _def, pair<string, unsigned int> _effect) {
    numOfEffects=1;
    type=_type;
    defense=_def;
    effects.push_back(_effect);
    gearScore=gearScoreCal();
}

unsigned long int Armor::gearScoreCal() {
    int effectScore=0;
    if(numOfEffects!=0) {
        for (int i = 0; i < numOfEffects; i++) {
            effectScore+=effects[i].second;
        }
    }
    return effectScore;
}

Armor::Armor(ArmorType _type, unsigned int _def, vector<pair<string, unsigned int>> _effect) {
    type=_type;
    defense=_def;
    for(int i=0;i<_effect.size();i++) {
        numOfEffects++;
        pair<string,unsigned int> current=_effect[i];
        effects.push_back(current);
    }
    gearScore=gearScoreCal();
}

ArmorType Armor::getArmorType() {
    return type;
}

unsigned long int Armor::getGearScore() {
    return gearScore;
}

unsigned int Armor::getDefense() {
    return defense;
}

void Armor::addEffect(string name, unsigned int power) {
    int index=effectExist(name);
    if(index==-1) {
        pair<string, unsigned int> newEffect;
        newEffect.first = name;
        newEffect.second = power;
        effects.push_back(newEffect);
        numOfEffects++;
    }else{
        effects[index].second=power;
    }
    gearScore=gearScoreCal();
}

int Armor::effectExist(string name) {
    for(int i=0;i<numOfEffects;i++){
        if(effects[i].first==name){
            return  i;
        }
    }
    return -1;
}

void Armor::addEffect(pair<string, unsigned int> _effect) {
    this->addEffect(_effect.first,_effect.second);
}

void Armor::removeEffect(string name, unsigned int power) {
    int index=effectExist(name);
    if(index!=-1){
        effects.erase(effects.begin()+index);
        numOfEffects--;
       gearScore=gearScoreCal();
    }
}

void Armor::removeEffect(pair<string, unsigned int> _effect) {
    this->removeEffect(_effect.first,_effect.second);
}

void Armor::removeEffect(string name) {
    int index=effectExist(name);
    if(index!=-1){
        effects.erase(effects.begin()+index);
        numOfEffects--;
        gearScore=gearScoreCal();
    }
}

void Armor::changePowerOfEffect(string name, unsigned int newPower) {
    int index=effectExist(name);
    if(index!=-1){
        effects[index].second=newPower;
        gearScore=gearScoreCal();
    }
}

void Armor::changeType(ArmorType _type) {
    type=_type;
}

void Armor::changeDefense(unsigned int def) {
    defense=def;
}

int Armor::getNumOfEffects() {
    return numOfEffects;
}



