//
// Created by Tegu on 11.4.2021 г..
//

#include "Armor.h"

Armor::Armor() {
    name = "";
    numOfEffects = 0;
    gearScore = 0;
    type = Null;
    defense = 0;
}

Armor::Armor(string _name, ArmorType _type, unsigned int _def) {
    name = _name;
    numOfEffects = 0;
    gearScore = 0;
    type = _type;
    defense = _def;
}

Armor::Armor(string _name, ArmorType _type, unsigned int _def, pair<string, unsigned int> _effect) {
    name = _name;
    numOfEffects = 1;
    type = _type;
    defense = _def;
    effects.push_back(_effect);
    gearScore = gearScoreCal();
}

unsigned long int Armor::gearScoreCal() {
    int effectScore = 0;
    if (numOfEffects != 0) {
        for (int i = 0; i < numOfEffects; i++) {
            effectScore += effects[i].second;
        }
    }
    return effectScore;
}

Armor::Armor(string _name, ArmorType _type, unsigned int _def, vector<pair<string, unsigned int>> _effect) {
    name = _name;
    type = _type;
    defense = _def;
    for (int i = 0; i < _effect.size(); i++) {
        numOfEffects++;
        pair<string, unsigned int> current = _effect[i];
        effects.push_back(current);
    }
    gearScore = gearScoreCal();
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

void Armor::addEffect(string _name, unsigned int power) {
    int index = effectExist(_name);
    if (index == -1) {
        pair<string, unsigned int> newEffect;
        newEffect.first = _name;
        newEffect.second = power;
        effects.push_back(newEffect);
        numOfEffects++;
    } else {
        effects[index].second = power;
    }
    gearScore = gearScoreCal();
}

int Armor::effectExist(string _name) {
    for (int i = 0; i < numOfEffects; i++) {
        if (effects[i].first == _name) {
            return i;
        }
    }
    return -1;
}

void Armor::addEffect(pair<string, unsigned int> _effect) {
    this->addEffect(_effect.first, _effect.second);
}

void Armor::removeEffect(string _name, unsigned int power) {
    int index = effectExist(_name);
    if (index != -1) {
        effects.erase(effects.begin() + index);
        numOfEffects--;
        gearScore = gearScoreCal();
    }
}

void Armor::removeEffect(pair<string, unsigned int> _effect) {
    this->removeEffect(_effect.first, _effect.second);
}

void Armor::removeEffect(string _name) {
    int index = effectExist(_name);
    if (index != -1) {
        effects.erase(effects.begin() + index);
        numOfEffects--;
        gearScore = gearScoreCal();
    }
}

void Armor::changePowerOfEffect(string _name, unsigned int newPower) {
    int index = effectExist(_name);
    if (index != -1) {
        effects[index].second = newPower;
        gearScore = gearScoreCal();
    }
}

void Armor::changeType(ArmorType _type) {
    type = _type;
}

void Armor::changeDefense(unsigned int def) {
    defense = def;
}

int Armor::getNumOfEffects() {
    return numOfEffects;
}

string Armor::getName() {
    return name;
}

void Armor::changeName(string newName) {
    name = newName;
}

int Armor::getSlots() {
    return numOfSlots;
}

bool operator==(const Armor &_lhs, const Armor &_rhs) {
    if (_lhs.name == _rhs.name &&
        _lhs.numOfEffects == _rhs.numOfEffects &&
        _lhs.defense == _rhs.defense &&
        _lhs.type == _rhs.type &&
        _lhs.gearScore == _rhs.gearScore) {
        for (int i = 0; i < _lhs.numOfEffects; i++) {
            if (_lhs.effects[i] != _rhs.effects[i]) {
                return false;
            }
        }
        return true;
    }
}

bool operator!=(const Armor &_lhs, const Armor &_rhs) {
    return !(_lhs == _rhs);
}

Armor &Armor::operator&(const Armor &other) {

    if (this != &other) {
        this->type = other.type;
        this->defense = other.defense;
        this->numOfEffects = other.numOfEffects;
        this->effects = other.effects;
        this->name = other.name;
        this->gearScore = other.gearScore;
    }
    return *this;

}

ostream &operator<<(ostream &out, Armor &rhs) {
    string _type="";
    switch (rhs.type) {
        case Cloth:
            _type="Cloth";
            break;
        case Leather:
            _type="Leather";
            break;
        case Mail:
            _type="Mail";
            break;
        case Kevlar:
            _type="Kevlar";
            break;
        case PE:
            _type="PE";
            break;
        case UHMWPE:
            _type="UHMWPE";
            break;
    }
    out<<rhs.name<<"\n Type: "<<_type<<"\n Def: "<<rhs.defense<<" EXP\n EFFECTS: \n";
    for(int i=0;i<rhs.numOfEffects;i++){
        out<<i<<". "<<rhs.effects[i].first << " with power " << rhs.effects[i].second<<" EXP\n";
    }
    out<<"TOTAL GEAR SCORE:"<<rhs.getGearScore()<<"\n";
    return out;
}



