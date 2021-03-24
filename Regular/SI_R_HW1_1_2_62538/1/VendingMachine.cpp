//
// Created by Tegu on 23.3.2021 г..
//

#include "VendingMachine.h"

bool equal(const char a[], const char b[]) {
    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i] != b[i])
            return 0;
    }
    return 1;
}

VendingMachine::VendingMachine() {
    drinks = nullptr;
    money = 0.0;
    numOfDrinks = 0;
}

VendingMachine::VendingMachine(const VendingMachine &from) {
    this->numOfDrinks = from.numOfDrinks;
    this->money = from.money;
    this->drinks = new Drink[from.numOfDrinks];
    for (int i = 0; i < from.numOfDrinks; i++) {
        this->drinks[i] = from.drinks[i];
    }
}

VendingMachine &VendingMachine::operator=(const VendingMachine &from) {
    if (this != &from) {
        delete[] this->drinks;
        this->numOfDrinks=from.numOfDrinks;
        this->money=from.money;
        this->drinks=new Drink[numOfDrinks];
        for (int i = 0; i < numOfDrinks; i++) {
            this->drinks[i] = from.drinks[i];
        }
    }
    return *this;
}

bool VendingMachine::add_drink(const Drink &to_add) {

    if (numOfDrinks == 0) {
        drinks = new Drink[1];
        drinks[0] = Drink(to_add);
        numOfDrinks++;
        return true;
    }
    for (int i = 0; i < numOfDrinks; i++) {
        if (equal(to_add.get_name(), this->drinks[i].get_name())) {
            return false;
        }
    }
    Drink *d = new Drink[this->numOfDrinks + 1];

    for (int i = 0; i < numOfDrinks; i++) {
        d[i] = this->drinks[i];
    }
    delete[] this->drinks;

    d[numOfDrinks] = to_add;
    numOfDrinks++;

    this->drinks = new Drink[this->numOfDrinks];
    for (int i = 0; i < numOfDrinks; i++) {
        this->drinks[i] = d[i];
    }
//        cout<<"FUNC: \n";
//        for (int i = 0; i < numOfDrinks; i++) {
//            drinks[i].print();
//        }

    delete[]d;

    return true;
}

int VendingMachine::buy_drink(const char *drink_name, const double money) {
    for (int i = 0; i < numOfDrinks; i++) {
        if (equal(drink_name, this->drinks[i].get_name())) {
            if(drinks[i].get_price()<=money) {
                this->remove_drink(i);
                this->money+=money;
                return 0;
            }else{
                this->money+=money;
                return 1;
            }
        }
    }
    return 2;
}

double VendingMachine::get_income() const {
    return money;
}

//______________________________________________________

void VendingMachine::print() const {
    for (int i = 0; i < numOfDrinks; i++) {
        drinks[i].print();
        cout<<"\n";
    }
    cout << "Total income: " << money << endl;
}

VendingMachine::~VendingMachine() {
    delete[] drinks;
}

void VendingMachine::remove_drink(int index) {
    Drink *d = new Drink[this->numOfDrinks-1];

    for (int i = 0; i < numOfDrinks; i++) {
        if(i!=index) {
            d[i] = this->drinks[i];
        }
    }
    delete[] this->drinks;
    numOfDrinks--;

    this->drinks = new Drink[this->numOfDrinks];
    for (int i = 0; i < numOfDrinks; i++) {
        this->drinks[i] = d[i];
    }
    delete[]d;
}
