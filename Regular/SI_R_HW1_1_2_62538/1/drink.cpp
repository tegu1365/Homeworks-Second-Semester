
#include "drink.hpp"

//bool equal(char a[], char b[]) {
//    for (int i = 0; a[i] != '\0'; i++) {
//        if (a[i] != b[i])
//            return 0;
//    }
//    return 1;
//}

Drink::Drink(const char *init_name, const int init_calories, const double &init_quantity, const double &init_price) {
    name = new char[strlen(init_name) + 1];
    strcpy(name, init_name);
    calories = init_calories;
    quantity = init_quantity;
    price = init_price;
}

Drink::Drink(const Drink &other) {
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->calories = other.calories;
    this->quantity = other.quantity;
    this->price = other.price;
}

Drink &Drink::operator=(const Drink &other) {
    if (this != &other) {
        delete[] this->name;

        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->calories = other.calories;
        this->quantity = other.quantity;
        this->price = other.price;
    }
    return *this;
}

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
    delete[] name;
    name = new char[strlen(new_name) + 1];
    strcpy(name, new_name);
}

//______________________________________________________

void Drink::print() const {
    cout << name << endl << "Cal.:" << calories << "  " << quantity << " L.\n" << fixed << setprecision(2) << price
         << " lv." << endl;
}

Drink::~Drink() {
    delete[] name;
}

Drink::Drink() {
    name = nullptr;
    calories = 0;
    price = 0;
    quantity = 0;
}

//bool operator==(const Drink &lhs, const Drink &rhs) {
//
//    return (equal(lhs.name, rhs.name) && lhs.calories == rhs.calories && lhs.quantity == rhs.quantity &&
//            lhs.price == rhs.price);
//}
