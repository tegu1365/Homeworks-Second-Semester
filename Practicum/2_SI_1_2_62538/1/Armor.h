//
// Created by Tegu on 11.4.2021 г..
//

#ifndef INC_1_ARMOR_H
#define INC_1_ARMOR_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

enum ArmorType{
    Cloth,
    Leather,
    Mail,
    Kevlar,
    PE,
    UHMWPE,
    Null
};

class Armor {
private:
    string name;
    ArmorType type;
    unsigned int defense;
    vector<pair<string,unsigned int>> effects;
    unsigned long int gearScore;
    int numOfEffects;

    unsigned long int gearScoreCal();
    int effectExist(string name);

    int numOfSlots=1;
public:
    Armor();
    Armor(string name,ArmorType _type, unsigned int _def);
    Armor(string name,ArmorType _type,unsigned int _def, pair<string,unsigned int> _effect);
    Armor(string name,ArmorType _type,unsigned int _def, vector<pair<string,unsigned int>> _effect);
    ArmorType getArmorType();
    unsigned long int getGearScore();
    unsigned int getDefense();
    void addEffect(string name, unsigned int power);
    void addEffect(pair<string,unsigned int> _effect);
    void removeEffect(string name,unsigned int power);
    void removeEffect(pair<string,unsigned int> _effect);
    void removeEffect(string name);
    void changePowerOfEffect(string name,unsigned int newPower);
    void changeType(ArmorType _type);
    void changeDefense(unsigned int def);
    string  getName();
    void changeName(string newName);
    int getNumOfEffects();
    int getSlots();
    friend bool operator==(const Armor& _lhs,const Armor& _rhs);
    friend bool operator!=(const Armor& _lhs,const Armor& _rhs);
    Armor& operator&(const Armor& other);
    friend ostream& operator<<(ostream& out,  Armor& rhs);

};


#endif //INC_1_ARMOR_H
