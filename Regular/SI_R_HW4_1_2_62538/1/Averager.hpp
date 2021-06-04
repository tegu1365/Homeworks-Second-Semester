//
// Created by Tegu on 4.6.2021 г..
//

#ifndef INC_1_AVERAGER_HPP
#define INC_1_AVERAGER_HPP
#include "Message.hpp"
#include <string>
#include <vector>

class Averager {
private:
    vector<Message> signals;
    double average();
public:
    string id;

    Averager(string id);

    void signal(Message);
    int read();
};


#endif //INC_1_AVERAGER_HPP
