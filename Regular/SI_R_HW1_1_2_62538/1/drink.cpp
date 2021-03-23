//
// Created by Tegu on 23.3.2021 г..
//

#include "drink.h"

Drink::Drink(const char *init_name, const int init_calories, const double &init_quantity, const double &init_price) {
    name=new char[strlen(init_name)+1];
    strcpy(name,init_name);
    calories=init_calories;
    quantity=init_quantity;
    price=init_price;
}

Drink::Drink(const Drink &) {

}

//Drink &Drink::operator=(const Drink &) {
//    return <#initializer#>;
//}

const char *Drink::get_name() const {
    return name;
}

int Drink::get_calories() const {
    return calories;
}

double Drink::get_quantity() const {
    return quantity;
}

double Drink::get_price() const {
    return price;
}

void Drink::set_name(const char *new_name) {

}

//______________________________________________________

void Drink::print() const {
    cout<<name<<endl<<"Cal.:"<<calories<<"  "<<quantity<<" L.\n"<<price<<" lv."<<endl;
}
