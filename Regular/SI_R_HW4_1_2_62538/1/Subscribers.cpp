//
// Created by Tegu on 4.6.2021 г..
//

#include "Subscribers.hpp"

Subscribers::Subscribers(string id) {
this->id=id;
}

void Subscribers::signal(Message toAdd) {
    signals.push_back(toAdd);
}

int Subscribers::read() {
    if(signals.size()==0){return 0;}
    return this->sample();
}
