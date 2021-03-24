//
// Created by Tegu on 23.3.2021 г..
//

#ifndef INC_1_DRINK_H
#define INC_1_DRINK_H
#include <iostream>
#include <iomanip>

using namespace std;

class Drink {
private:
    //name,calories,quantity,price
    char* name;
    int calories;
    double quantity;
    double price;
public:
    Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price);
    Drink(const Drink&);
    Drink& operator=(const Drink&);

    const char* get_name() const;
    int get_calories() const;
    double get_quantity() const;
    double get_price() const;

    void set_name(const char* new_name);

    void print() const;
};


#endif //INC_1_DRINK_H
