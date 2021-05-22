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

#ifndef INC_1_MAGICCARD_HPP
#define INC_1_MAGICCARD_HPP

#include "Card.hpp"

class MagicCard : virtual public Card {
private:
    Type type;
public:
    MagicCard(const string name = "", const string effect = "", const unsigned int rarity=0, const Type type = NT);

    MagicCard(const char *text);

    Type getType() const;

    void setType(const Type type);

    string toString() const;

    Card* clone();
};


#endif //INC_1_MAGICCARD_HPP
