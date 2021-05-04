//
// Created by Tegu on 4.5.2021 г..
//

#include "LimitedTwowayCounter.hpp"

LimitedTwowayCounter::LimitedTwowayCounter(const int _min, const int _max, const int initial, const unsigned int step)
        : Counter(initial, step), LimitedCounter(_max, initial, step), TwowayCounter(initial, step) {
    this->_min = _min;
}

void LimitedTwowayCounter::increment() {
    LimitedCounter::increment();
}

void LimitedTwowayCounter::decrement() {
    if((total-step)>=_min) {
        TwowayCounter::decrement();
    }
}

int LimitedTwowayCounter::getMin() const {
    return _min;
}
