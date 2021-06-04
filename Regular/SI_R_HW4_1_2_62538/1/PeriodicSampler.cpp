//
// Created by Tegu on 4.6.2021 г..
//

#include "PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(string id, size_t period):Subscribers(id) {
    this->period=period;
}

double PeriodicSampler::sample() const{
    double last=0;
    int size=signals.size();
    for(int i=0;i<size;i++){
        if((i+1) % period != 0) {
            last = signals[i].data;
        }
    }
    return last;
}

PeriodicSampler *PeriodicSampler::clone() const {
    return new PeriodicSampler(*this);
}

void PeriodicSampler::signal(Message toAdd) {
    Subscribers::signal(toAdd);
}

int PeriodicSampler::read()const {
    return Subscribers::read();
}

