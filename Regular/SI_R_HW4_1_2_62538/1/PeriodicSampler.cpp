//
// Created by Tegu on 4.6.2021 г..
//

#include "PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(string id, size_t period):Subscribers(id) {
    this->period=period;
}

double PeriodicSampler::sample() const{
    double last=signals[0].data;
    int size=signals.size();
    for(int i=0;i<size;i++){
        int n=i+1;
        if(n % period != 0) {
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

