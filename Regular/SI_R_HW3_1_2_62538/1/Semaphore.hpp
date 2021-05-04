//
// Created by Tegu on 4.5.2021 г..
//

#ifndef INC_1_SEMAPHORE_HPP
#define INC_1_SEMAPHORE_HPP
#include "LimitedTwowayCounter.hpp"

class Semaphore: public LimitedTwowayCounter {
private:
    bool available;
public:
    Semaphore(const bool available=0,const int _min=0,const int _max=1,const int initial=0,const unsigned int step=1);
    bool isAvailable()const;
    void wait();
    void signal();
};


#endif //INC_1_SEMAPHORE_HPP
