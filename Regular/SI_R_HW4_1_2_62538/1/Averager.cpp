//
// Created by Tegu on 4.6.2021 г..
//

#include "Averager.hpp"

Averager::Averager(string id) {
    this->id=id;
}

void Averager::signal(Message toAdd) {
    signals.push_back(toAdd);
}

int Averager::read() {
    if(signals.size()==0){return 0;}
    return this->average();
}

double Averager::average() {
    double ave=0;
    for(int i=0;i<signals.size();i++){
        ave+=signals[i].data;
    }
    return ave/signals.size();
}
