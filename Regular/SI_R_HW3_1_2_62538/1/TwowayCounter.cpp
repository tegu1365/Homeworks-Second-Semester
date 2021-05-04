//
// Created by Tegu on 4.5.2021 г..
//

#include "TwowayCounter.hpp"

TwowayCounter::TwowayCounter(const int initial, const unsigned int step) : Counter(initial, step) {

}

void TwowayCounter::decrement() {
    this->total-=step;
}
