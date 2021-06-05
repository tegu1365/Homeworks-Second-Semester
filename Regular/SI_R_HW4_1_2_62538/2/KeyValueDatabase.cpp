//
// Created by Tegu on 5.6.2021 г..
//

#include <stdexcept>
#include "KeyValueDatabase.hpp"

KeyValueDatabase::KeyValueDatabase(const string &name, const string &location, const string &extension)
                                    : Object(name,location,extension){

}

void KeyValueDatabase::add_entry(const pair<string, int> &entry) {
    for(auto x:this->entries){
        if(x.first==entry.first){
            throw invalid_argument("The key exist already.");
        }
    }

    this->entries.push_back(entry);

}

int KeyValueDatabase::get_value(const string &key) const {
    for(auto x:this->entries){
        if(x.first==key){
            return x.second;
        }
    }

    throw invalid_argument("The key does not exist.");
}

bool KeyValueDatabase::operator!=(const KeyValueDatabase *other) const {
    return !(this==other);
}

bool KeyValueDatabase::operator==(const KeyValueDatabase *other) const {
   // KeyValueDatabase* sth= dynamic_cast<KeyValueDatabase*>(other);
    if(this->entries.size()==other->entries.size()){
        for(size_t i=0;i<entries.size();i++){
            if(this->entries[i].second!=other->entries[i].second){
                return false;
            }
            if(this->entries[i].first!=other->entries[i].first){
                return false;
            }
        }
    } else{
        return false;
    }
    return true;
}

string KeyValueDatabase::to_string() const {
    string result=name+"\n"+location+"\n"+extension+"\n";
    for(auto x:entries){
        result.append(x.first+":"+std::to_string(x.second)+"\n");
    }
    return result;
}

void KeyValueDatabase::from_string(const string& str) {
    vector<string>lines;
    string current = "";
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == '\n') {
           // current.push_back('\n');
            lines.push_back(current);
            current = "";
        } else {
            char a = str[i];
            current.push_back(a);
        }
    }
    this->location=lines[1];
    this->name=lines[0];
    this->extension=lines[2];
    string key="";
    int entry=0;
    for(size_t j=3;j<lines.size();j++) {
        string line=lines[j];
        for (size_t i =0; i < lines[j].size(); i++) {
            if (line[i] == ':') {
                key = current;
                current = "";
            } else {
                char a = line[i];
                current.push_back(a);
            }
        }
        entry = stoi(current);
        pair<string, int> k;
        k.first = key;
        k.second = entry;
        entries.push_back(k);
        entry = 0;
        key = "";
        current="";
    }
}

string KeyValueDatabase::debug_print() const {
    string result="";
    for(auto x:entries){
        result.append("{"+x.first+":"+std::to_string(x.second)+"}\n");
    }
    return result;
}

bool KeyValueDatabase::operator!=(const Comparable *other) const {
    return KeyValueDatabase::operator!=((KeyValueDatabase*)other);
}

bool KeyValueDatabase::operator==(const Comparable *other) const {
    return KeyValueDatabase::operator==((KeyValueDatabase*)other);
}
