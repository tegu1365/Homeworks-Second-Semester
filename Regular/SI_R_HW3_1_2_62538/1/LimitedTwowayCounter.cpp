//
// Created by Tegu on 4.5.2021 г..
//

#include "LimitedTwowayCounter.hpp"
#include <iostream>

LimitedTwowayCounter::LimitedTwowayCounter(const int _min, const int _max, const int initial, const unsigned int step)
        : Counter(initial, step), LimitedCounter(_max, initial, step), TwowayCounter(initial, step) {
    this->_min = _min;
}

void LimitedTwowayCounter::increment() {
    this->LimitedCounter::increment();
}

void LimitedTwowayCounter::decrement() {
   // std::cout<<total<<"-"<<step<<"="<<total-step<<">="<<_min<<std::endl;
    int newTotal=this->total- this->step;
    if(newTotal>=this->_min) {
        this->total=newTotal;
    }
}

int LimitedTwowayCounter::getMin() const {
    return _min;
}
