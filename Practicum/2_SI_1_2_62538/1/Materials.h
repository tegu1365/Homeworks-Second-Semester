//
// Created by Tegu on 10.4.2021 г..
//

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
