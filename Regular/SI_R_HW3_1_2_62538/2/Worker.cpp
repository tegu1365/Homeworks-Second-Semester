//
// Created by Tegu on 8.5.2021 г..
//

#include "Worker.hpp"

Worker::Worker(const string &name,const double salary) {
    this->name=name;
    this->salary=salary;
}

string Worker::getName() const {
    return name;
}

double Worker::getSalary() const {
    return salary;
}

void Worker::setInitialSalary(const double amount) {
    if(salary==0){
        salary=amount;
    }
}

void Worker::setSalary(const double salary) {
    this->salary=salary;
}
