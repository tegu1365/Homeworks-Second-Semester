//
// Created by Tegu on 4.6.2021 г..
//

#ifndef INC_1_MOVINGAVERAGER_HPP
#define INC_1_MOVINGAVERAGER_HPP
#include "Subscribers.hpp"

class MovingAverager:public Subscribers {
public:
    double sample();
public:
    size_t windowSize;

    MovingAverager(string id, size_t windowSize);
};


#endif //INC_1_MOVINGAVERAGER_HPP
