//
// Created by Tegu on 4.5.2021 г..
//

#ifndef INC_1_COUNTER_HPP
#define INC_1_COUNTER_HPP


class Counter {
protected:
    int initial;
    unsigned int step;
    int total;
public:
    Counter(const int initial=0,const unsigned int step=1);//it works for all 3 constructors
    void increment();
    int getTotal()const;
    unsigned int getStep()const;
};


#endif //INC_1_COUNTER_HPP
