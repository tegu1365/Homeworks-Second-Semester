//
// Created by Tegu on 4.5.2021 г..
//

#include "Counter.hpp"

Counter::Counter(const int initial, const unsigned int step) {
    this->initial=initial;
    this->step=step;
    this->total=initial;
}

void Counter::increment() {
    this->total+=this->step;
}

int Counter::getTotal() const {
    return total;
}

unsigned int Counter::getStep() const {
    return step;
}
