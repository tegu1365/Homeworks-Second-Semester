#include "VendingMachine.hpp"

int main() {
    Drink d = Drink("Soda", 1000, 0.5, 1.1);
    //d.print();
    Drink a = Drink(d);
    //a.print();
    Drink k = Drink("Soda1", 1000, 0.5, 1.10);
    //cout<<(a==d)<<endl;
    VendingMachine v = VendingMachine();
    cout << "ADD d: " << v.add_drink(d) << endl;
    cout << "ADD d2: " << v.add_drink(d) << endl;
    cout << "ADD a: " << v.add_drink(a) << endl;
    cout << "ADD k: " << v.add_drink(k) << endl;
    cout << "ADD cola: " << v.add_drink(Drink("Cola", 1550, 1, 2.00)) << endl;
    cout << "_____________________________\n";
    v.print();
//    VendingMachine v2=VendingMachine();
//    v2=v;
//    cout<<"\nV2:\n\n";
//    v2.print();
    cout << "Buy cola for 1.50:" << v.buy_drink("Cola", 1.50) << endl;
    cout << "_____________________________\n";
    v.print();
    cout << "_____________________________\n";
    cout << "Buy cola for 2.00:" << v.buy_drink("Cola", 2.30) << endl;
    cout << "_____________________________\n";
    v.print();
    cout << "_____________________________\n";
    cout << "try to buy soda3:" << v.buy_drink("Soda3", 2.00) << endl;
    cout << "_____________________________\n";
    v.print();

    // cout<<v.get_income();
    return 0;
}
