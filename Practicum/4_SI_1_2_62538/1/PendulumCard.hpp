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


#ifndef INC_1_PENDULUMCARD_HPP
#define INC_1_PENDULUMCARD_HPP
#define MIN_SCALE 1
#define MAX_SCALE 13

#include "MagicCard.hpp"
#include "MonsterCard.hpp"

class PendulumCard : virtual public MagicCard, virtual public MonsterCard {
private:
    unsigned short scale;
public:
    PendulumCard(const string name = "", const string effect = "",const unsigned int rarity=0, const unsigned int atk = 0,
                 const unsigned int def = 0, const unsigned short scale = 1, const Type type = NT);

    PendulumCard(const char *text);

    unsigned short getScale() const;

    void setScale(const unsigned short scale);

    string toString() const;

    Card* clone();
};


#endif //INC_1_PENDULUMCARD_HPP
