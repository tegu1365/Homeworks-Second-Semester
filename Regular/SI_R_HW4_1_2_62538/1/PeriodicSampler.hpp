//
// Created by Tegu on 4.6.2021 г..
//

#ifndef INC_1_PERIODICSAMPLER_HPP
#define INC_1_PERIODICSAMPLER_HPP
#include "Message.hpp"
#include "Subscribers.hpp"
#include <string>
#include <vector>

class PeriodicSampler: public Subscribers {
private:
    size_t period;
    double sample();
public:
    PeriodicSampler(string id, size_t period);
};


#endif //INC_1_PERIODICSAMPLER_HPP
