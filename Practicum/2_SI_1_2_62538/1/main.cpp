#include <assert.h>
#include <iostream>

#include "Money.h"

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
}

int main() {
    runTest();
    cout << "End" <<endl;
    return 0;
}
