//
// Created by Tegu on 5.6.2021 г..
//

#ifndef INC_2_SERIALIZABLE_HPP
#define INC_2_SERIALIZABLE_HPP
#include <string>

using namespace std;

class Serializable {
public:
    virtual string to_string()const =0;
    virtual void from_string(const string& str) =0;
};


#endif //INC_2_SERIALIZABLE_HPP
