//
// Created by Tegu on 4.5.2021 г..
//

#include "Semaphore.hpp"

Semaphore::Semaphore(const bool available, const int _min, const int _max, const int initial, const unsigned int step)
        : LimitedTwowayCounter(_min, _max, initial, step) {
    if (available) {
        this->initial = 1;
    } else {
        this->initial = 0;
    }
    this->step = 1;
    this->_min = 0;
    this->_max = 1;
}

bool Semaphore::isAvailable() const {
    return total>0;
}

void Semaphore::signal() {
    this->LimitedTwowayCounter::increment();
}

void Semaphore::wait() {
    this->LimitedTwowayCounter::decrement();
}

