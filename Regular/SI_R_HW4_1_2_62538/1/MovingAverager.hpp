//
// Created by Tegu on 4.6.2021 г..
//

#ifndef INC_1_MOVINGAVERAGER_HPP
#define INC_1_MOVINGAVERAGER_HPP
#include "Message.hpp"
#include <string>
#include <vector>

class MovingAverager {
public:
    vector<Message> signals;
    double average();

public:
    string id;
    size_t windowSize;

    MovingAverager(string id, size_t windowSize);

    void signal(Message);

    int read();


};


#endif //INC_1_MOVINGAVERAGER_HPP
