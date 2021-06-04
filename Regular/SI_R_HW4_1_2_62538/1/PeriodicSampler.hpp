//
// Created by Tegu on 4.6.2021 г..
//

#ifndef INC_1_PERIODICSAMPLER_HPP
#define INC_1_PERIODICSAMPLER_HPP
#include "Message.hpp"
#include <string>

class PeriodicSampler {
public:
    string id;

    PeriodicSampler(string id, size_t period);

    void signal(Message);
    int read();
};


#endif //INC_1_PERIODICSAMPLER_HPP
