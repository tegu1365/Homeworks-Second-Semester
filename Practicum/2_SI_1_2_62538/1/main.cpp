#include <assert.h>
#include <iostream>

#include "Money.h"
#include "Materials.h"
using namespace std;


void runTest(){
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

    Materials materialEss=Materials(MaterialType::essence);
    assert(materialEss.getType()==MaterialType::essence);
    assert(materialEss.getQuantityPerSlot()==10);

    Materials materialCL=Materials(MaterialType::cloth);
    assert(materialCL.getType()==MaterialType::cloth);
    assert(materialCL.getQuantityPerSlot()==20);
}

int main() {
    runTest();
    cout << "End" <<endl;
    return 0;
}
