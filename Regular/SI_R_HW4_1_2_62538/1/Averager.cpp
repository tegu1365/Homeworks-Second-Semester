//
// Created by Tegu on 4.6.2021 г..
//

#include "Averager.hpp"

Averager::Averager(string id):Subscribers(id) {
}

double Averager::sample() {
    double ave=0;
    for(auto x:this->signals){
        ave=ave+x.data;
    }
    return ave/this->signals.size();
}

Averager *Averager::clone() const {
    return new Averager(*this);
}