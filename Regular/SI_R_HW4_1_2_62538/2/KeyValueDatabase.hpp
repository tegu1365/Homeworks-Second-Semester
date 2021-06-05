//
// Created by Tegu on 5.6.2021 г..
//

#ifndef INC_2_KEYVALUEDATABASE_HPP
#define INC_2_KEYVALUEDATABASE_HPP
#include <string>
#include <vector>
#include "Object.hpp"
using namespace std;

class KeyValueDatabase: public Object {
private:
  vector<pair<string,int>> entries;
public:
    KeyValueDatabase(const string& name, const string& location, const string& extension);

    void add_entry(const pair<string, int>& entry);
    int get_value(const string& key) const;

    bool operator!=(const KeyValueDatabase* other)const;
    bool operator==(const KeyValueDatabase* other)const;

    bool operator!=(const Comparable* other)const;
    bool operator==(const Comparable* other)const;
    string to_string()const;
    void from_string(const string& str);
    string debug_print()const;
};


#endif //INC_2_KEYVALUEDATABASE_HPP
