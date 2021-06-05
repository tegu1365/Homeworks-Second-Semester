//
// Created by Tegu on 5.6.2021 г..
//

#ifndef INC_2_KEYVALUEDATABASE_HPP
#define INC_2_KEYVALUEDATABASE_HPP
#include <string>

using namespace std;

class KeyValueDatabase {
public:
    KeyValueDatabase(const string& name, const string& location, const string& extension);

    void add_entry(const pair<string, int>& entry);
    int get_value(const string& key) const;
};


#endif //INC_2_KEYVALUEDATABASE_HPP
