//
// Created by Tegu on 4.6.2021 г..
//

#include "SimplePublisher.hpp"

void SimplePublisher::subscribe(Averager * averager) {
    this->subs.push_back(averager);
}

void SimplePublisher::subscribe(MovingAverager *movingAverager) {
    this->subs.push_back(movingAverager);
}

void SimplePublisher::subscribe(PeriodicSampler *periodicSampler) {
    this->subs.push_back(periodicSampler);
}

void SimplePublisher::unsubscribe(Averager * averager) {
    int size=subs.size();
    for(int i=0;i<size;i++){
        if(subs[i]->id==averager->id){
          //  delete this->subs[i];
            subs.erase(subs.begin() + i);
        }
    }
}
void SimplePublisher::unsubscribe(MovingAverager *movingAverager) {
    int size=subs.size();
    for(int i=0;i<size;i++){
        if(subs[i]->id==movingAverager->id){
        //    delete this->subs[i];
            subs.erase(subs.begin() + i);
        }
    }
}

void SimplePublisher::unsubscribe(PeriodicSampler * periodicSampler) {
    int size=subs.size();
    for(int i=0;i<size;i++){
        if(subs[i]==periodicSampler){
         //   delete this->subs[i];
            subs.erase(subs.begin() + i);
        }
    }
}


void SimplePublisher::signal(Message message) {
    int size=subs.size();
    for(int i=0;i<size;i++){
      subs[i]->signal(message);
    }
}

//SimplePublisher::~SimplePublisher() {
//    for (auto x : this->subs) {
//        delete x;
//    }
//}
//
//SimplePublisher &SimplePublisher::operator=(const SimplePublisher &rhs) {
//    if (this != &rhs) {
//        for (auto x : subs) {
//            delete x;
//        }
//        subs.clear();
//
//        for (auto x : rhs.subs) {
//            subs.push_back(x);
//        }
//    }
//    return *this;
//}
