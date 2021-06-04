//
// Created by Tegu on 4.6.2021 г..
//

#include "MovingAverager.hpp"

MovingAverager::MovingAverager(string id, size_t windowSize):Subscribers(id) {
    this->windowSize=windowSize;
}

double MovingAverager::sample()const {
    if(signals.size()<windowSize){return 0;}
    double ave=0;
    int size=signals.size();
    for(unsigned int i=1;i<=windowSize;i++){
        ave+=signals[size-i].data;
    }
    return ave/windowSize;
}

MovingAverager *MovingAverager::clone() const {
    return new MovingAverager(*this);
}

void MovingAverager::signal(Message toAdd) {
    Subscribers::signal(toAdd);
}

int MovingAverager::read()const {
    return Subscribers::read();
}

