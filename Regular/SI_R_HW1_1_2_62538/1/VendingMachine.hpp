

#ifndef INC_1_VENDINGMACHINE_HPP
#define INC_1_VENDINGMACHINE_HPP

#include "drink.hpp"

class VendingMachine {
private:
    Drink *drinks;
    double money;
    int numOfDrinks;
public:
    VendingMachine();

    VendingMachine(const VendingMachine &from);

    VendingMachine &operator=(const VendingMachine &from);

    bool add_drink(const Drink &to_add);

    int buy_drink(const char *drink_name, const double money);

    double get_income() const;

    void remove_drink(int index);

    void print() const;

    ~VendingMachine();
};


#endif //INC_1_VENDINGMACHINE_HPP
