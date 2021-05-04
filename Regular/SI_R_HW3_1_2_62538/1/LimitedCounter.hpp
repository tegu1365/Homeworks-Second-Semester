//
// Created by Tegu on 4.5.2021 г..
//

#ifndef INC_1_LIMITEDCOUNTER_HPP
#define INC_1_LIMITEDCOUNTER_HPP
#include "Counter.hpp"

class LimitedCounter:virtual public Counter{
private:
    int max;
public:
    LimitedCounter(const int max,const int initial=0,const unsigned int step=1);
    void increment();
    int getMax()const;
};


#endif //INC_1_LIMITEDCOUNTER_HPP
