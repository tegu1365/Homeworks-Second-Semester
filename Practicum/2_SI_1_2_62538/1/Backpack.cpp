//
// Created by Tegu on 10.4.2021 г..
//

#include "Backpack.h"

template<> Backpack<Money>::Backpack() {
    fullSlots=1;
    maxSlots=1;
    slots.emplace_back();
}

template<> Backpack<Materials>::Backpack() {
    fullSlots=0;
    maxSlots=16;
}

template<>bool Backpack<Money>::isFull() {//always false because we have infinity space for money
    return false;
}

template<>bool Backpack<Money>::isEmpty() {
    if(fullSlots==0){
        return true;
    }
    return (slots[0].getBronzeCoins()+slots[0].getSilverCoins()+slots[0].getGoldCoins()==0);
}

template<typename B>
void Backpack<B>::Empty() {
    slots.clear();
    fullSlots=0;
}

template<>unsigned short Backpack<Materials>::numOfFullSlots() {
    return fullSlots;
}
template<>unsigned short Backpack<Money>::numOfFullSlots() {
    return fullSlots;
}

template<> int Backpack<Money>::addToBackpack(Money _sth) {
    if(fullSlots==0){
        slots.push_back(_sth);
        return 0;
    }
    slots[0].addBronze(_sth.getBronzeCoins());
    slots[0].addSilver(_sth.getSilverCoins());
    slots[0].addGold(_sth.getGoldCoins());
    return 1;
}

template<>int Backpack<Materials>::addToBackpack(Materials _sth) {
    if(fullSlots!=maxSlots) {
        unsigned short quantityPerSlot = _sth.getQuantityPerSlot();
        if(fullSlots!=0) {
            for (int i = 0; i < fullSlots; i++) {
                if (slots[i].getType() == _sth.getType()) {
                    if (slots[i].getQuantity() != slots[i].getQuantityPerSlot()) {
                        unsigned int newQuantity = slots[i].getQuantity() + _sth.getQuantity();
                        if (newQuantity - quantityPerSlot > 0) {
                            unsigned short addToOldSlot = quantityPerSlot - slots[i].getQuantity();
                            slots[i].addMaterial(addToOldSlot);
                            //____________________________
                            unsigned int forNewSlot = newQuantity - quantityPerSlot;
                            if (forNewSlot < quantityPerSlot) {
                                slots.push_back(Materials(_sth.getType(), forNewSlot));
                                fullSlots++;
                                return 1;
                            } else {
                                int j = forNewSlot / quantityPerSlot;
                                while (j > 0 || fullSlots != maxSlots) {
                                    unsigned short add = forNewSlot - j * quantityPerSlot;
                                    slots.push_back(Materials(_sth.getType(), add));
                                    fullSlots++;
                                    forNewSlot -= add;
                                    j--;
                                }
                                if (fullSlots != maxSlots) {
                                    slots.push_back(Materials(_sth.getType(), forNewSlot));
                                    fullSlots++;
                                }
                                return 2;
                            }
                        } else {
                            slots[i].addMaterial(newQuantity - slots[i].getQuantity());
                            return 3;
                        }
                    }
                }
            }
        }

        unsigned int newQ=_sth.getQuantity();
        int j = newQ / quantityPerSlot;

        while (j > 0 && fullSlots != maxSlots) {
            unsigned short add = newQ - j * quantityPerSlot;
            slots.push_back(Materials(_sth.getType(), add));
            fullSlots++;
            newQ -= add;
            j--;
        }

        if (fullSlots != maxSlots) {
            slots.push_back(Materials(_sth.getType(), newQ));
            fullSlots++;
        }

        return 4;
    }
    return 0;
}

template<>bool Backpack<Materials>::isEmpty() {
    return fullSlots==0;
}

template<>bool Backpack<Materials>::isFull() {//if all slots are on full capacity
    if(fullSlots==maxSlots){
        for(int i=0;i<maxSlots;i++){
            if(slots[i].getQuantity()!=slots[i].getQuantityPerSlot()) {
                return false;
            }
        }
        return true;
    }
    return false;
}




