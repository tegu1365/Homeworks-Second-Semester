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

#ifndef INC_1_CARD_H
#define INC_1_CARD_H

#include <iostream>
#include <string>

using namespace std;

enum Type {
    trap, buff, spell, NT
};

class Card {
protected:
    string name;
    string effect;
public:
    Card(const string name = "", const string effect = "");

    string getName() const;

    string getEffect() const;

    void setName(const string name);

    void setEffect(const string effect);

    string toString() const;
};


#endif //INC_1_CARD_H
