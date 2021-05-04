//
// Created by Tegu on 4.5.2021 г..
//

#include "LimitedCounter.hpp"

LimitedCounter::LimitedCounter(const int _max, const int initial, const unsigned int step):Counter(initial, step) {
    this->_max=_max;
}

void LimitedCounter::increment() {
    if((total+step)<=_max) {
        Counter::increment();
    }
}

int LimitedCounter::getMax() const {
    return _max;
}
