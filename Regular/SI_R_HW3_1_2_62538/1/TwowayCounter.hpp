//
// Created by Tegu on 4.5.2021 г..
//

#ifndef INC_1_TWOWAYCOUNTER_HPP
#define INC_1_TWOWAYCOUNTER_HPP
#include "Counter.hpp"

class TwowayCounter:virtual public Counter{
public:
    TwowayCounter(const int initial=0,const unsigned int step=1);
    void decrement();
};


#endif //INC_1_TWOWAYCOUNTER_HPP
