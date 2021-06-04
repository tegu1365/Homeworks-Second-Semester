//
// Created by Tegu on 4.6.2021 г..
//

#ifndef INC_1_AVERAGER_HPP
#define INC_1_AVERAGER_HPP
#include "Message.hpp"
#include "Subscribers.hpp"
#include <string>
#include <vector>

class Averager: public Subscribers {
private:
    vector<Message> signals;
    double sample();
public:
    string id;

    Averager(string id);
};


#endif //INC_1_AVERAGER_HPP
