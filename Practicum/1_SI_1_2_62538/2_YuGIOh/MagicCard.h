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

#ifndef INC_2_YUGIOH_MAGICCARD_H
#define INC_2_YUGIOH_MAGICCARD_H


#include <iostream>

using namespace std;

enum Type {
    trap, buff, spell,NT
};

class MagicCard {
private:
    char name[26];
    char effect[100];
    Type type;
public:
    MagicCard();
    MagicCard(char _name[], char _effect[], Type _type);

    char *getName();

    char *getEffect();

    Type getType();

    void setName(char _name[]);

    void setEffect(char _effect[]);

    void setType(Type _type);

    void print() const;
};



#endif //INC_2_YUGIOH_MAGICCARD_H
