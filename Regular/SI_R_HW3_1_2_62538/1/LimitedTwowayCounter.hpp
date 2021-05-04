//
// Created by Tegu on 4.5.2021 г..
//

#ifndef INC_1_LIMITEDTWOWAYCOUNTER_HPP
#define INC_1_LIMITEDTWOWAYCOUNTER_HPP
#include "LimitedCounter.hpp"
#include "TwowayCounter.hpp"

class LimitedTwowayCounter: public TwowayCounter, public LimitedCounter {
protected:
    int _min;
public:
    LimitedTwowayCounter(const int _min,const int _max,const int initial=0,const unsigned int step=1);
    void increment();
    void decrement();
    int getMin()const;
};


#endif //INC_1_LIMITEDTWOWAYCOUNTER_HPP
