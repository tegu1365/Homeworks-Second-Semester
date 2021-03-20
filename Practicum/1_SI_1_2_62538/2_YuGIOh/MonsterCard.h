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

#ifndef INC_2_YUGIOH_MONSTERCARD_H
#define INC_2_YUGIOH_MONSTERCARD_H


#include <iostream>

using namespace std;

class MonsterCard {
private:
    char name[26];
    unsigned int atk;
    unsigned int def;
public:
    MonsterCard();

    MonsterCard(char _name[], unsigned int _ATK, unsigned int _DEF);

    unsigned int getATK() const;

    unsigned int getDEF() const;

    char * getName() ;

    void setName(char _name[]);

    void setATK(unsigned int _ATK);

    void setDEF(unsigned int _DEF);

    void print() const;
};

#endif //INC_2_YUGIOH_MONSTERCARD_H
