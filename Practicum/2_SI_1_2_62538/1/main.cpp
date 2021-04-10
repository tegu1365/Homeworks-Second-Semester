#include <assert.h>
#include <iostream>

#include "Money.h"
#include "Materials.h"
#include "Backpack.h"
using namespace std;


void runTestForBackpack(){
    Money money=Money();
    assert(money.getBronzeCoins() == 0);
    money.addMoney(20);
    money.addSilver(2);
    money.addGold(1);
    assert(money.getBronzeCoins() == 20);
    assert(money.getSilverCoins() == 2);
    assert(money.getGoldCoins()==1);

    Materials material1=Materials();
    assert(material1.getType()==MaterialType::none);
    assert(material1.getQuantityPerSlot()==0);

    Materials materialEss=Materials(MaterialType::essence,12);
    assert(materialEss.getType()==MaterialType::essence);
    assert(materialEss.getQuantityPerSlot()==10);
    assert(materialEss.getQuantity()==12);

    Materials materialCL=Materials(MaterialType::cloth,10);
    assert(materialCL.getType()==MaterialType::cloth);
    assert(materialCL.getQuantityPerSlot()==20);
    assert(materialCL.getQuantity()==10);

    Backpack<Money> moneyPoch =Backpack<Money>();
    assert(moneyPoch.isEmpty()==true);
    assert(moneyPoch.isFull()==false);
    //moneyPoch.addToBackpack(money);
    assert(moneyPoch.addToBackpack(money)==1);
    assert(moneyPoch.numOfFullSlots()==1);

    Backpack<Materials> backpackMat=Backpack<Materials>();
    assert(backpackMat.isFull()==false);
    assert(backpackMat.isEmpty()==true);
    Materials toAdd=Materials(MaterialType::cloth,23);
    assert(backpackMat.addToBackpack(toAdd)==4);
    assert(backpackMat.isEmpty()== false);
    assert(backpackMat.numOfFullSlots()==2);
    assert(backpackMat.addToBackpack(materialEss)==4);
    assert(backpackMat.numOfFullSlots()==4);
    assert(backpackMat.addToBackpack(materialEss)==1);
    assert(backpackMat.numOfFullSlots()==5);
}

int main() {
    runTestForBackpack();
    cout << "End" <<endl;
    return 0;
}
