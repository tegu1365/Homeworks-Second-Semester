/**
*	Solution to homework assignment 3
*	Object Oriented Programming Course
*	Faculty of Mathematics and Informatics of Sofia University
*	Summer semester 2020/2021
*
*	@author Teodora Dimitrova Petkova
*	@idnumber 62538
*	@task 1
*	@compiler VC
*/


#ifndef INC_1_PENDULUMCARD_H
#define INC_1_PENDULUMCARD_H
#define MIN_SCALE 1
#define MAX_SCALE 13

#include "MagicCard.h"
#include "MonsterCard.h"

class PendulumCard : virtual public MagicCard, virtual public MonsterCard {
private:
    unsigned short scale;
public:
    PendulumCard(const string name = "", const string effect = "", const unsigned int atk = 0,
                 const unsigned int def = 0, const Type type = NT, const unsigned short scale = 1);

    PendulumCard(const char *text);

    unsigned short getScale() const;

    void setScale(const unsigned short scale);

    string toString() const;
};


#endif //INC_1_PENDULUMCARD_H
