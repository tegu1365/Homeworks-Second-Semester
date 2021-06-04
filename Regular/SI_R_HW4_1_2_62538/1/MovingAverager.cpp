//
// Created by Tegu on 4.6.2021 г..
//

#include "MovingAverager.hpp"

MovingAverager::MovingAverager(string id, size_t windowSize):Subscribers(id) {
    this->windowSize=windowSize;
}

double MovingAverager::sample() {
    double ave=0;
    int size=signals.size();
    for(int i=1;i<=windowSize;i++){
        ave+=signals[size-i].data;
    }
    return ave/windowSize;
}

