//
// Created by Tegu on 4.6.2021 г..
//

#include "MovingAverager.hpp"

MovingAverager::MovingAverager(string id, size_t windowSize) {
    this->id=id;
    this->windowSize=windowSize;
}

void MovingAverager::signal(Message toAdd) {
    signals.push_back(toAdd);
}

int MovingAverager::read() {
    if(signals.size()==0){return 0;}
    return this->average();
}

double MovingAverager::average() {
    double ave=0;
    int size=signals.size();
    for(int i=1;i<=windowSize;i++){
        ave+=signals[size-i].data;
    }
    return ave/windowSize;
}

