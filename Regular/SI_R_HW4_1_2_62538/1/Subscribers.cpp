//
// Created by Tegu on 4.6.2021 г..
//

#include "Subscribers.hpp"

Subscribers::Subscribers(string id) {
this->id=id;
}

void Subscribers::signal(Message toAdd) {
    this->signals.push_back(toAdd);
}

int Subscribers::read()const {
    if(signals.size()==0){return 0;}
    return this->sample();
}

bool operator==(const Subscribers &rhs, const Subscribers &lhs) {
    return rhs.id==lhs.id;
}
