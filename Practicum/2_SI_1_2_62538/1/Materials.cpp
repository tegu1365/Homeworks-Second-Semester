//
// Created by Tegu on 10.4.2021 г..
//

#include "Materials.h"

Materials::Materials() {
    type=none;
    quantityPerSlot=0;
}
Materials::Materials(MaterialType _type) {
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
}

unsigned short Materials::getQuantityPerSlot() {
    return quantityPerSlot;
}

MaterialType Materials::getType() {
    return type;
}
