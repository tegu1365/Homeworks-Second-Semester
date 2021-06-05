//
// Created by Tegu on 4.6.2021 г..
//

#include "Repository.hpp"

void Repository::add(Averager *averager) {
    subs.push_back(averager->clone());
}

void Repository::add(MovingAverager *movingAverager) {
    subs.push_back(movingAverager->clone());

}

void Repository::add(PeriodicSampler *periodicSampler) {
    subs.push_back(periodicSampler->clone());
}

Subscribers *Repository::get(std::string id) {
    for (auto x:subs) {
        if (id == x->id) {
            return x;
        }
    }
    return nullptr;
}

Repository::~Repository() {
    for (auto x:subs) {
        delete x;
    }
}

Repository &Repository::operator=(const Repository &rhs){
    if (this != &rhs) {
        for (auto x : this->subs) {
            delete x;
        }
        this->subs.clear();

        for (auto x : rhs.subs) {
            this->subs.push_back(x->clone());
        }
    }
    return *this;
}

Repository::Repository(const Repository &other) {
    for (auto x : other.subs) {
        subs.push_back(x->clone());
    }
}