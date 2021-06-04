//
// Created by Tegu on 4.6.2021 г..
//

#ifndef INC_1_SUBSCRIBERS_HPP
#define INC_1_SUBSCRIBERS_HPP

#include "Message.hpp"
#include <string>
#include <vector>

class Subscribers {
protected:
    vector<Message> signals;
    virtual double sample()=0;
public:
    Subscribers(string id);
    string id;
    void signal(Message toAdd);
    int read();
    friend bool operator==(const Subscribers& rhs,const Subscribers& lhs);
    virtual Subscribers * clone() const = 0;
};


#endif //INC_1_SUBSCRIBERS_HPP
