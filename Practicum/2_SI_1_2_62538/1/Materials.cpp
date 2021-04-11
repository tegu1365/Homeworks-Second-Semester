//
// Created by Tegu on 10.4.2021 г..
//

#include "Materials.h"

Materials::Materials() {
    type=none;
    quantityPerSlot=0;
    quantity=0;
}
Materials::Materials(MaterialType _type, unsigned short _quantity) {
    type=_type;
    switch (type) {
        case essence:
            quantityPerSlot=10;
            break;
        case herbs:
        case ores:
        case cloth:
            quantityPerSlot=20;
            break;
        default:
            quantityPerSlot=0;
            break;
    }
    quantity=_quantity;
}

unsigned short Materials::getQuantityPerSlot() {
    return quantityPerSlot;
}

MaterialType Materials::getType() {
    return type;
}

unsigned short Materials::getQuantity() {
    return quantity;
}

void Materials::addMaterial(unsigned short q) {
    quantity+=q;
}

void Materials::removeMaterial(unsigned short _quantity) {
    if(_quantity<=quantity){
        quantity-=_quantity;
    }
}
