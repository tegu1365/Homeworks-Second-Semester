//
// Created by Tegu on 4.5.2021 г..
//

#include "LimitedCounter.hpp"

LimitedCounter::LimitedCounter(const int max, const int initial, const unsigned int step):Counter(initial, step) {
    this->max=max;
}

void LimitedCounter::increment() {
    if(total<max) {
        Counter::increment();
    }
}

int LimitedCounter::getMax() const {
    return max;
}
