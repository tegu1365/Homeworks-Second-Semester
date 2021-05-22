/**
*	Solution to homework assignment 4
*	Object Oriented Programming Course
*	Faculty of Mathematics and Informatics of Sofia University
*	Summer semester 2020/2021
*
*	@author Teodora Dimitrova Petkova
*	@idnumber 62538
*	@task 1
*	@compiler VC
*/

#ifndef INC_1_MONSTERCARD_HPP
#define INC_1_MONSTERCARD_HPP

#include "Card.hpp"

class MonsterCard : virtual public Card {
private:
    unsigned int atk;
    unsigned int def;
public:
    MonsterCard(const string name = "", const string effect = "",const unsigned int rarity=0, const unsigned int atk = 0,
                const unsigned int def = 0);

    MonsterCard(const char *text);

    unsigned int getATK() const;

    unsigned int getDEF() const;

    void setATK(const unsigned int atk);

    void setDEF(const unsigned int def);

    string toString() const;

    Card* clone();
};


#endif //INC_1_MONSTERCARD_H