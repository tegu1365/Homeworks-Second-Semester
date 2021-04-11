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

#ifndef INC_1_MATERIALS_H
#define INC_1_MATERIALS_H
#include <iostream>
using namespace std;
enum MaterialType{
    herbs,
    ores ,
    cloth,
    essence,
    none
};

class Materials {
private:
    MaterialType type;
    unsigned short quantityPerSlot;
    unsigned short quantity;
public:
    Materials();
    Materials(MaterialType _type, unsigned short _quantity);
    unsigned short getQuantityPerSlot();
    MaterialType getType();
    unsigned short getQuantity();
    void removeMaterial(unsigned short _quantity);
    void addMaterial(unsigned short q);

    Materials& operator=(const Materials& other);
    friend ostream& operator<<(ostream& out,  Materials& rhs);
};


#endif //INC_1_MATERIALS_H
