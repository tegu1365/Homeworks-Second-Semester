//
// Created by Tegu on 10.4.2021 г..
//

#ifndef INC_1_MATERIALS_H
#define INC_1_MATERIALS_H

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
    void addMaterial(unsigned short q);
};


#endif //INC_1_MATERIALS_H
