//
// Created by Tegu on 4.6.2021 г..
//

#include <iostream>
#include "MovingAverager.hpp"

MovingAverager::MovingAverager(string id, size_t windowSize):Subscribers(id) {
    this->windowSize=windowSize;
}

double MovingAverager::sample()const {

    double ave=0;
    int size=signals.size();
    int num=windowSize;
    if(signals.size()<windowSize){
        num=signals.size();
    }
    for(unsigned int i=1;i<=num;i++){
        ave+=signals[size-i].data;
       // cout<<size-i<<" ";
    }
    //cout<<endl;
    return ave/num;
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

