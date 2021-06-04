//
// Created by Tegu on 4.6.2021 г..
//

#include "PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(string id, size_t period):Subscribers(id) {
    this->period=period;
}

double PeriodicSampler::sample() {
    double last=0;
    for(int i=0;i<signals.size();i++){
        if((i+1) % period != 0) {
            last = signals[i].data;
        }
    }
    return last;
}

