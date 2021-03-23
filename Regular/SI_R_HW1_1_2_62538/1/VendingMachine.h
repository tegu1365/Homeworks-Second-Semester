//
// Created by Tegu on 23.3.2021 г..
//

#ifndef INC_1_VENDINGMACHINE_H
#define INC_1_VENDINGMACHINE_H

#include "drink.h"

class VendingMachine {
private:
    Drink* drinks;
    double money;
    int numOfDrinks;
public:
    VendingMachine();
    VendingMachine(const VendingMachine& from);
    VendingMachine& operator=(const VendingMachine& from);

    bool add_drink(const Drink& to_add);
    int buy_drink(const char* drink_name, const double money);

    double get_income() const;

    void print()const;
};


#endif //INC_1_VENDINGMACHINE_H
