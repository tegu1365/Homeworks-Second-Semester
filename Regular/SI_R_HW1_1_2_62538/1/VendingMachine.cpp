//
// Created by Tegu on 23.3.2021 г..
//

#include "VendingMachine.h"

VendingMachine::VendingMachine() {
    drinks= nullptr;
    money=0.0;
    numOfDrinks=0;
}

VendingMachine::VendingMachine(const VendingMachine &from) {

}

//VendingMachine &VendingMachine::operator=(const VendingMachine &from) {
//    return <#initializer#>;
//}

bool VendingMachine::add_drink(const Drink &to_add) {
    return false;
}

int VendingMachine::buy_drink(const char *drink_name, const double money) {
    return 0;
}

double VendingMachine::get_income() const {
    return money;
}

//______________________________________________________

void VendingMachine::print() const {
    for (int i=0;i<numOfDrinks;i++){
        drinks[i].print();
    }
    cout<<"Total income: "<<money<<endl;
}
