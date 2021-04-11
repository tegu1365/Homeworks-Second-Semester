//
// Created by Tegu on 11.4.2021 г..
//

#include "Weapon.h"

Weapon::Weapon() {
    name= "";
    type=zero;
    form=null;
    hitDamage[0]=0;
    hitDamage[1]=0;
    numOfEffects=0;
    weaponScore=0;
}

Weapon::Weapon(string name,WeaponType _type, WeaponForm _form, unsigned int *_hitDamage) {
    this->name=name;
    this->form=_form;
    this->relationFormType(_type);
    this->hitDamage[0]=_hitDamage[0];
    this->hitDamage[1]=_hitDamage[1];
    this->numOfEffects=0;
    this->weaponScore=weaponScoreCal();

}

Weapon::Weapon(string name,WeaponType _type, WeaponForm _form, unsigned int *_hitDamage, pair<string, unsigned int> _effect) {
   this->name=name;
    hitDamage[0]=_hitDamage[0];
    hitDamage[1]=_hitDamage[1];
    numOfEffects=1;
    effect.push_back(_effect);
    form=_form;
    this->relationFormType(_type);
    weaponScore=weaponScoreCal();
}

Weapon::Weapon(string name,WeaponType _type, WeaponForm _form, unsigned int *_hitDamage,
               vector<pair<string, unsigned int>> _effect) {
    this->name=name;
    form=_form;
    hitDamage[0]=_hitDamage[0];
    hitDamage[1]=_hitDamage[1];
    for(int i=0;i<_effect.size();i++) {
        numOfEffects++;
        pair<string,unsigned int> current=_effect[i];
        effect.push_back(current);
    }
    this->relationFormType(_type);
    weaponScore=weaponScoreCal();
}

WeaponForm Weapon::getWeaponForm() {
    return form;
}

WeaponType Weapon::getWeaponType() {
    return type;
}

unsigned int *Weapon::getHitDamage() {
    return hitDamage;
}

pair<string, unsigned int> Weapon::getEffect(string _name) {
    for(int i=0;i<numOfEffects;i++){
        if(effect[i].first==_name){
            return  effect[i];
        }
    }
    return pair<string,unsigned int>("Null",0);
}

double Weapon::getWeaponScore() {
    return weaponScore;
}

void Weapon::changeWeaponForm(WeaponForm newWeaponForm) {
    form=newWeaponForm;
    this->relationFormType(type);
    weaponScore=weaponScoreCal();
}

void Weapon::relationFormType(WeaponType _type) {
    switch(form){
        case dagger:
            type=one_handed;
            break;
        case staff:
        case bow:
        case lance:
        case garroteWire:
            type=two_handed;
            break;
        default:
            type=_type;
            break;
    }
}

double Weapon::weaponScoreCal() {
    int effectScore=0;
    if(numOfEffects!=0) {
        for (int i = 0; i < numOfEffects; i++) {
          effectScore+=effect[i].second;
        }
    }
    double _weaponScore=((hitDamage[0]+hitDamage[1])/2.0+effectScore);
    if(type==one_handed){
        _weaponScore*=0.75;
    }
    if(type==two_handed){
        _weaponScore*=1.5;
    }
    return _weaponScore;
}

void Weapon::changeWeaponType(WeaponType newType) {
    this->relationFormType(newType);
    weaponScore=weaponScoreCal();
}

void Weapon::addEffect(string _name, unsigned int power) {
    int index=effectExist(_name);
    if(index==-1) {
        pair<string, unsigned int> newEffect;
        newEffect.first = _name;
        newEffect.second = power;
        effect.push_back(newEffect);
        numOfEffects++;
    }else{
        effect[index].second=power;
    }
    weaponScore=weaponScoreCal();
}

int Weapon::effectExist(string _name) {
    for(int i=0;i<numOfEffects;i++){
        if(effect[i].first==_name){
            return  i;
        }
    }
    return -1;
}

void Weapon::addEffect(pair<string, unsigned int> _effect) {
    this->addEffect(_effect.first,_effect.second);
}

void Weapon::removeEffect(string _name, unsigned int power) {
    int index=effectExist(_name);
    if(index!=-1){
        effect.erase(effect.begin()+index);
        numOfEffects--;
        weaponScore=weaponScoreCal();

    }
}

void Weapon::removeEffect(pair<string, unsigned int> _effect) {
    this->removeEffect(_effect.first,_effect.second);
}

void Weapon::changePowerOfEffect(string _name, unsigned int newPower) {
    int index=effectExist(_name);
    if(index!=-1){
        effect[index].second=newPower;
        weaponScore=weaponScoreCal();
    }
}

int Weapon::getNumOfEffects() {
    return numOfEffects;
}

void Weapon::removeEffect(string _name) {
    int index=effectExist(_name);
    if(index!=-1){
        effect.erase(effect.begin()+index);
        numOfEffects--;
        weaponScore=weaponScoreCal();

    }
}

unsigned short Weapon::getSlots() {
    return (short)type;
}

void Weapon::changeName(string newName) {
    name=newName;
}

string Weapon::getName() {
    return name;
}

bool operator==(const Weapon &_lhs, const Weapon &_rhs) {
    if(_lhs.name==_rhs.name &&
       _lhs.numOfEffects==_rhs.numOfEffects &&
       _lhs.form==_rhs.form &&
       _lhs.type==_rhs.type &&
       _lhs.weaponScore==_rhs.weaponScore &&
       _lhs.hitDamage==_rhs.hitDamage){
        for(int i=0;i<_lhs.numOfEffects;i++){
            if(_lhs.effect[i]!=_rhs.effect[i]){
                return false;
            }
        }
        return true;
    }
}

bool operator!=(const Weapon &_lhs, const Weapon &_rhs) {
    return !(_lhs==_rhs);
}



