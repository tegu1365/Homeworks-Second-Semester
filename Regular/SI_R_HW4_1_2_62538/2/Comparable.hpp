//
// Created by Tegu on 5.6.2021 г..
//

#ifndef INC_2_COMPARABLE_HPP
#define INC_2_COMPARABLE_HPP


class Comparable {
public:
    Comparable()=default;
    virtual bool operator!=(const Comparable* other)const=0;
    virtual bool operator==(const Comparable* other)const=0;

    virtual ~Comparable()=default;
};


#endif //INC_2_COMPARABLE_HPP
