//
// Created by Tegu on 11.4.2021 г..
//

#ifndef INC_1_WEAPON_H
#define INC_1_WEAPON_H
#include <string>
#include <vector>
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
    Weapon(WeaponType _type,WeaponForm _form, unsigned int _hitDamage[]);
    Weapon(WeaponType _type,WeaponForm _form, unsigned int _hitDamage[],pair<string,unsigned int>_effect);
    Weapon(WeaponType _type,WeaponForm _form, unsigned int _hitDamage[],vector<pair<string,unsigned int>>_effect);
    WeaponForm getWeaponForm();
    WeaponType getWeaponType();
    unsigned int* getHitDamage();
    pair<string,unsigned int> getEffect(string name);
    double getWeaponScore();
    void changeWeaponForm(WeaponForm newWeaponForm);
    void changeWeaponType(WeaponType newType);
    void addEffect(string name,unsigned int power);
    void addEffect(pair<string,unsigned int> _effect);
    void removeEffect(string name,unsigned int power);
    void removeEffect(pair<string,unsigned int> _effect);
    void removeEffect(string name);
    void changePowerOfEffect(string name,unsigned int newPower);

    int getNumOfEffects();
};


#endif //INC_1_WEAPON_H
