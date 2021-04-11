/**
*	Solution to homework assignment 2
*	Object Oriented Programming Course
*	Faculty of Mathematics and Informatics of Sofia University
*	Summer semester 2020/2021 *
*	@author Teodora Petkova
*	@idnumber 62538
*	@task 1
*	@compiler VC
*/

#ifndef INC_1_WEAPON_H
#define INC_1_WEAPON_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;

enum WeaponType{//=numOfSlots
    one_handed=1,
    two_handed=2,
    zero=0
};

enum WeaponForm{
    axe,
    sword,
    dagger,//one hand
    mace,
    staff,//two hands
    lance,//two hands
    bow,//two hands
    garroteWire,//two hands
    null
};

class Weapon {
private:
    string name;
    WeaponType type;
    WeaponForm form;
    unsigned int hitDamage[2];
    vector<pair<string, unsigned int>> effect;
    int numOfEffects;
    double weaponScore;

    void relationFormType(WeaponType _type);
    double weaponScoreCal();
    int effectExist(string name);
public:
    Weapon();
    Weapon(string name,WeaponType _type,WeaponForm _form, unsigned int _hitDamage[]);
    Weapon(string name,WeaponType _type,WeaponForm _form, unsigned int _hitDamage[],pair<string,unsigned int>_effect);
    Weapon(string name,WeaponType _type,WeaponForm _form, unsigned int _hitDamage[],vector<pair<string,unsigned int>>_effect);
    WeaponForm getWeaponForm();
    WeaponType getWeaponType();
    unsigned int* getHitDamage();
    pair<string,unsigned int> getEffect(string _name);
    double getWeaponScore();
    void changeWeaponForm(WeaponForm newWeaponForm);
    void changeWeaponType(WeaponType newType);
    void addEffect(string _name,unsigned int power);
    void addEffect(pair<string,unsigned int> _effect);
    void removeEffect(string _name,unsigned int power);
    void removeEffect(pair<string,unsigned int> _effect);
    void removeEffect(string _name);
    void changePowerOfEffect(string _name,unsigned int newPower);
    void changeName(string newName);
    string getName();

    unsigned short getSlots();
    int getNumOfEffects();

    friend bool operator==(const Weapon &_lhs, const Weapon &_rhs);
    friend bool operator!=(const Weapon &_lhs, const Weapon &_rhs);
    Weapon& operator=(const Weapon& other);

    friend ostream& operator<<(ostream& out, const Weapon& rhs);

};


#endif //INC_1_WEAPON_H
