//
// Created by Tegu on 4.6.2021 г..
//

#include "BacklogPublisher.hpp"

void BacklogPublisher::subscribe(Averager * averager) {
    this->subs.push_back(averager->clone());
    oldSignals(averager);
}

void BacklogPublisher::subscribe(MovingAverager *movingAverager) {
    this->subs.push_back(movingAverager->clone());
    oldSignals(movingAverager);

}

void BacklogPublisher::subscribe(PeriodicSampler *periodicSampler) {
    this->subs.push_back(periodicSampler->clone());
    oldSignals(periodicSampler);

}

void BacklogPublisher::oldSignals(Subscribers *sub) {
    if(signals.size()!=0){
        for(auto x:signals){
            sub->signal(x);
        }
    }
}

void BacklogPublisher::unsubscribe(Averager * averager) {
    for(int i=0;i<subs.size();i++){
        if(subs[i]->id==averager->id){
            delete this->subs[i];
            subs.erase(subs.begin() + i);
        }
    }
}
void BacklogPublisher::unsubscribe(MovingAverager *movingAverager) {
    for(int i=0;i<subs.size();i++){
        if(subs[i]->id==movingAverager->id){
            delete this->subs[i];
            subs.erase(subs.begin() + i);
        }
    }
}

void BacklogPublisher::unsubscribe(PeriodicSampler * periodicSampler) {
    for(int i=0;i<subs.size();i++){
        if(subs[i]==periodicSampler){
            delete this->subs[i];
            subs.erase(subs.begin() + i);
        }
    }
}

void BacklogPublisher::signal(Message message) {
    for(auto x:subs){
        x->signal(message);
    }
    signals.push_back(message);
}

/*BacklogPublisher::BacklogPublisher(const BacklogPublisher &backlogPublisher) {
    for (auto x : backlogPublisher.subs) {
        this->subs.push_back(x->clone());
    }
    for (auto x : backlogPublisher.signals) {
        this->signals.push_back(x);
    }
}*/

BacklogPublisher &BacklogPublisher::operator=(const BacklogPublisher &rhs) {
    if (this != &rhs) {
        for (auto x : subs) {
            delete x;
        }
        subs.clear();
        signals.clear();
        for (auto x : rhs.subs) {
            subs.push_back(x->clone());
        }
        for(auto x:rhs.signals){
            signals.push_back(x);
        }
    }
    return *this;
}

BacklogPublisher::~BacklogPublisher() {
    for(auto x:this->subs){
        delete x;
    }
}

