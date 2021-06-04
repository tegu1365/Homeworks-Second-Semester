//
// Created by Tegu on 4.6.2021 г..
//

#include "Averager.hpp"

Averager::Averager(string id):Subscribers(id) {
}

double Averager::sample() {
    double ave=0;
    for(int i=0;i<signals.size();i++){
        ave+=signals[i].data;
    }
    return ave/signals.size();
}
