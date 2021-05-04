//
// Created by Tegu on 4.5.2021 г..
//

#include "LimitedTwowayCounter.hpp"

LimitedTwowayCounter::LimitedTwowayCounter(const int min, const int max, const int initial, const unsigned int step)
        : Counter(initial, step), LimitedCounter(max, initial, step), TwowayCounter(initial, step) {
    this->min = min;
}

void LimitedTwowayCounter::increment() {
    LimitedCounter::increment();
}

void LimitedTwowayCounter::decrement() {
    if(total>min) {
        TwowayCounter::decrement();
    }
}

int LimitedTwowayCounter::getMin() const {
    return min;
}
