//
// Created by Tegu on 10.4.2021 г..
//

#ifndef INC_1_MATERIALS_H
#define INC_1_MATERIALS_H

enum MaterialType{
    herbs,
    ores ,
    cloth,
    essence
};

class Materials {
private:
    MaterialType type;
    unsigned short quantityPerSlot;
};


#endif //INC_1_MATERIALS_H
